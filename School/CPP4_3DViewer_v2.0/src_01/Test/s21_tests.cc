#include <gtest/gtest.h>

#include "../Model/error.h"
#include "../Model/model.h"

namespace s21 {
class ModelTest : public ::testing::Test {
 protected:
  static void SetUpTestCase() { my_model = Model::GetInstance(); }
  void SetUp() override {
    my_model->Clear();
    my_model->SetData("Test/cube.txt");
  }

  static void TearDownTestCase() {
    my_model->Clear();
    delete my_model;
  }

  static Model *my_model;
};
Model *ModelTest::my_model = nullptr;  // Определение статического члена класса

TEST_F(ModelTest, GetVertexesAmount) {
  EXPECT_EQ(8, my_model->GetVertexesAmount());
}

TEST_F(ModelTest, GetEdgesAmount) { EXPECT_EQ(18, my_model->GetEdgesAmount()); }

TEST_F(ModelTest, GetSurfacesSize) {
  EXPECT_EQ(12, my_model->GetCountSurfaces());
}

TEST_F(ModelTest, GetSurfaceSize) {
  EXPECT_EQ(3, my_model->GetVertexInSurface(0));
}

TEST_F(ModelTest, Test) {
  double answer[8][3] = {{-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1},
                         {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}};

  const std::vector<Point> &points = my_model->GetPoints();
  for (int i = 0; i < 8; ++i) {
    ASSERT_NEAR(points[i].GetX(), answer[i][0], 1e-7);
    ASSERT_NEAR(points[i].GetY(), answer[i][1], 1e-7);
    ASSERT_NEAR(points[i].GetZ(), answer[i][2], 1e-7);
  }
}

TEST_F(ModelTest, TestRotate) {
  double answer[8][3] = {{0.5, -1.5, 0.7071068},
                         {1.5, -0.5, -0.7071068},
                         {1.2071068, 1.2071068, 0.2928932},
                         {0.2071068, 0.2071068, 1.7071068},
                         {-1.2071068, -1.2071068, -0.2928932},
                         {-0.2071068, -0.2071068, -1.7071068},
                         {-0.5, 1.5, -0.7071068},
                         {-1.5, 0.5, 0.7071068}};

  my_model->Manipulate(Action::kRotate, 45, 45, 45);

  const std::vector<Point> &points = my_model->GetPoints();

  for (int i = 0; i < 8; ++i) {
    ASSERT_NEAR(points[i].GetX(), answer[i][0], 1e-7);
    ASSERT_NEAR(points[i].GetY(), answer[i][1], 1e-7);
    ASSERT_NEAR(points[i].GetZ(), answer[i][2], 1e-7);
  }
}

TEST_F(ModelTest, TestMove) {
  double answer[8][3] = {{4, -8, 2}, {6, -8, 2}, {6, -6, 2}, {4, -6, 2},
                         {4, -8, 0}, {6, -8, 0}, {6, -6, 0}, {4, -6, 0}};

  my_model->Manipulate(Action::kMove, 5, -7, 1);

  const std::vector<Point> &points = my_model->GetPoints();

  for (int i = 0; i < 8; ++i) {
    ASSERT_NEAR(points[i].GetX(), answer[i][0], 1e-7);
    ASSERT_NEAR(points[i].GetY(), answer[i][1], 1e-7);
    ASSERT_NEAR(points[i].GetZ(), answer[i][2], 1e-7);
  }
}

TEST_F(ModelTest, TestScale) {
  double answer[8][3] = {{-0.5, -0.5, 0.5},  {0.5, -0.5, 0.5},
                         {0.5, 0.5, 0.5},    {-0.5, 0.5, 0.5},
                         {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
                         {0.5, 0.5, -0.5},   {-0.5, 0.5, -0.5}};

  my_model->Manipulate(Action::kScale, 0, 0, 0, 50);

  const std::vector<Point> &points = my_model->GetPoints();

  for (int i = 0; i < 8; ++i) {
    ASSERT_NEAR(points[i].GetX(), answer[i][0], 1e-7);
    ASSERT_NEAR(points[i].GetY(), answer[i][1], 1e-7);
    ASSERT_NEAR(points[i].GetZ(), answer[i][2], 1e-7);
  }
}

TEST_F(ModelTest, Exception) {
  EXPECT_THROW(my_model->SetData("aasdasd.obj"), Error);
}
}  // namespace s21

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}