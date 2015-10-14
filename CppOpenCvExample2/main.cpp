#include <vector>
#include <opencv2/opencv.hpp>

std::vector<std::vector<double>> create_yx_grid(
  const int width,
  const int height
)
{
  std::vector<std::vector<double>> v(height,
    std::vector<double>(width,0.0)
  );
  for (int y=0; y!=height; ++y)
  {
    for (int x=0; x!=width; ++x)
    {
      assert(y >= 0);
      assert(y < static_cast<int>(v.size()));
      assert(x >= 0);
      assert(x < static_cast<int>(v[y].size()));
      v[y][x]
        = std::sin(
            static_cast<double>(x) * 3.14 * 4 / static_cast<double>(width)
        )
        + std::cos(
            static_cast<double>(y) * 3.14 * 4 / static_cast<double>(height)
        );
    }
  }
  return v;
}


cv::Mat create_image(const std::vector<std::vector<double>>& yx_grid)
{
  assert(!yx_grid.empty());
  const int height = yx_grid.size();
  assert(!yx_grid[0].empty());
  const int width = yx_grid[0].size();
  cv::Mat image = cv::Mat::zeros(cv::Size(width,height), CV_8UC3 );

 for (int y=0; y!=height; ++y)
  {
    for (int x=0; x!=width; ++x)
    {
      assert(y >= 0);
      assert(y < static_cast<int>(yx_grid.size()));
      assert(x >= 0);
      assert(x < static_cast<int>(yx_grid[y].size()));
      const double z = yx_grid[y][x];
      assert(z >= -2.0);
      assert(z <= 2.0);
      cv::Scalar color(
        128 + static_cast<int>(z * 64.0),
        128 + static_cast<int>(z * 64.0),
        128 + static_cast<int>(z * 64.0)
      );
      cv::rectangle(image,cv::Rect(x,y,1,1),color);
    }
  }
  return image;
}


int main() {
  const int width  = 640;
  const int height = 400;
  const cv::Mat image = create_image(create_yx_grid(width,height));
  const std::string window_name = "OpenCV example 2";
  cv::namedWindow(window_name, 0);
  cv::imshow(window_name, image);
  cv::resizeWindow(window_name,width,height);
  cv::waitKey(0);
}
