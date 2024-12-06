#include <gtest/gtest.h>
#include "../Struct.h"

TEST(Vidurkis, CalculateAverage) {
    Stud student("Jonas", "Jonaitis", {5, 6, 7, 8, 9}, 10);
    vidurkis(student);
    EXPECT_NEAR(student.vid, 7.0, 0.00);
    EXPECT_NEAR(student.rez, 8.8, 0.001);
}
