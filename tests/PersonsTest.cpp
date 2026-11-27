#include <gtest/gtest.h>
#include "Persons.hpp"

TEST(PersonsTest, CicloCRUD) {
    const int testId = 9992;

    Persons p(testId, "Stage Test", "Nombre Real Test", "1990-05-15", "2025-01-01");
    p.Eliminar_Borrar();
    p.Crear_Insertar();

    json res = p.Leer_Consultar(testId);
    ASSERT_FALSE(res.empty());
    EXPECT_EQ(res["stage_name"], "Stage Test");
    EXPECT_EQ(res["real_name"], "Nombre Real Test");

    
    Persons pMod(testId, "Stage Editado", "Nombre Real Test", "1990-05-15", "2025-01-01");
    pMod.Actualizar_Modificar(1);
    json resMod = pMod.Leer_Consultar(testId);
    EXPECT_EQ(resMod["stage_name"], "Stage Editado");

  
    pMod.Eliminar_Borrar();
    EXPECT_TRUE(pMod.Leer_Consultar(testId).empty());
}
