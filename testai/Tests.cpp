#include <gtest/gtest.h>
#include "../Struct.h"

TEST(Studentai, Konstruktorius) {
    Stud student;
    EXPECT_EQ(student.getVardas(), "petras");
    EXPECT_EQ(student.getPavarde(), "petraitis");
    EXPECT_EQ(student.rez, 10);
}

TEST(Studentai, geteriai_seteriai) {
    Stud student;
    student.setVardas("vardas");
    student.setPavarde("pavarde");
    EXPECT_EQ(student.getVardas(), "vardas");
    EXPECT_EQ(student.getPavarde(), "pavarde");
}

