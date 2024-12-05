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


TEST(Studentai, CopyKonstruktorius) {
    Stud student;
    student.setVardas("vardas");
    student.setPavarde("pavarde");
    student.vid = 5;
    student.med = 6;
    student.rez = 7;
    Stud student2 = student;
    EXPECT_EQ(student2.getVardas(), "vardas");
    EXPECT_EQ(student2.getPavarde(), "pavarde");
    EXPECT_EQ(student2.vid, 5);
    EXPECT_EQ(student2.med, 6);
    EXPECT_EQ(student2.rez, 7);
}