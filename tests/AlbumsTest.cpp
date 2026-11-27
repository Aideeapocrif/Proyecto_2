#include <gtest/gtest.h>
#include "Albums.hpp"

TEST(AlbumsTest, CicloCRUD) {
    const int testId = 9997;

    Albums a(testId, "/music/album_test", "Album Test", 2024, "/img/cover.png");
    a.Eliminar_Borrar();
    a.Crear_Insertar();

    
    json res = a.Leer_Consultar(testId);
    ASSERT_FALSE(res.empty());
    EXPECT_EQ(res["name"], "Album Test");
    EXPECT_EQ(res["year"], 2024);

    
    Albums aMod(testId, "/music/album_test", "Album Editado", 2024, "/img/cover.png");
    aMod.Actualizar_Modificar(2);
    json resMod = aMod.Leer_Consultar(testId);
    EXPECT_EQ(resMod["name"], "Album Editado");

    aMod.Eliminar_Borrar();
    EXPECT_TRUE(aMod.Leer_Consultar(testId).empty());
}
