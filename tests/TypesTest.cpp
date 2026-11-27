#include <gtest/gtest.h>
#include "Types.hpp"

TEST(TypesTest, CicloCRUD) {
    const int testId = 9999;

    
    Types t(testId, "Tipo Test");
    t.Eliminar_Borrar();
    t.Crear_Insertar();

    json res = t.Leer_Consultar(testId);
    ASSERT_FALSE(res.empty());
    EXPECT_EQ(res["description"], "Tipo Test");

    
    Types tMod(testId, "Tipo Editado");
    tMod.Actualizar_Modificar(1);
    json resMod = tMod.Leer_Consultar(testId);
    EXPECT_EQ(resMod["description"], "Tipo Editado");

  
    tMod.Eliminar_Borrar();
    EXPECT_TRUE(tMod.Leer_Consultar(testId).empty());
}
