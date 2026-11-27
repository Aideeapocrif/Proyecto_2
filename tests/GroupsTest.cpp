#include <gtest/gtest.h>
#include "Groups.hpp"

TEST(GroupsTest, CicloCRUD) {
    const int testId = 9993;

   
    Groups g(testId, "Grupo Test", "2010-01-01", "2020-01-01");
    g.Eliminar_Borrar();
    g.Crear_Insertar();

    
    json res = g.Leer_Consultar(testId);
    ASSERT_FALSE(res.empty());
    EXPECT_EQ(res["name"], "Grupo Test");
    EXPECT_EQ(res["start_date"], "2010-01-01");

    
    Groups gMod(testId, "Grupo Editado", "2010-01-01", "2020-01-01");
    gMod.Actualizar_Modificar(1);
    json resMod = gMod.Leer_Consultar(testId);
    EXPECT_EQ(resMod["name"], "Grupo Editado");

    
    gMod.Eliminar_Borrar();
    EXPECT_TRUE(gMod.Leer_Consultar(testId).empty());
}
