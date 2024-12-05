#include <gtest/gtest.h>
#include "../Struct.h"

// Test: Default constructor
TEST(StudTests, DefaultConstructor) {
    Stud student;
    EXPECT_EQ(student.getVardas(), "petras");
    EXPECT_EQ(student.getPavarde(), "petraitis");
    EXPECT_EQ(student.rez, 10);
}

// Test: File generation




// Test: Sorting

