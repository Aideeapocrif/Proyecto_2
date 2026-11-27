#include <gtest/gtest.h>
#include "Performers.hpp"
#include "Types.hpp"

TEST(PerformersTest, CicloCRUD) {
    const int testId = 9998;

    Types t(testId, "Tipo Test");
    Performers p(testId, testId, "Banda Test", "/img/test.png");

    p.Eliminar_Borrar();
    t.Eliminar_Borrar();

    
    t.Crear_Insertar();
    p.Crear_Insertar();

  
    json res = p.Leer_Consultar(testId);
    ASSERT_FALSE(res.empty());
    EXPECT_EQ(res["name"], "Banda Test");

   
    Performers pMod(testId, testId, "Banda Editada", "/img/test.png");
    pMod.Actualizar_Modificar(2);
    json resMod = pMod.Leer_Consultar(testId);
    EXPECT_EQ(resMod["name"], "Banda Editada");

    
    pMod.Eliminar_Borrar();
    t.Eliminar_Borrar();
    EXPECT_TRUE(pMod.Leer_Consultar(testId).empty());
}
