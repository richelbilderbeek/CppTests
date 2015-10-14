#include <QFile>
#include <QResource>

#include <opencv2/opencv.hpp>


int main()
{
  const std::string filename = "image.jpg";
  //Create the source image if it does not exist
  {
    if (!QFile::exists(filename.c_str()))
    {
      QFile f((std::string(":/images/") + filename).c_str());
      f.copy(filename.c_str());
    }
    assert(QFile::exists(filename.c_str()));
  }

  //Load the image
  const cv::Mat image_original = cv::imread(filename);
  assert(image_original.data);

  //Create the resulting image
  cv::Mat image_result;
  cv::cvtColor(image_original,image_result,CV_RGB2GRAY );
  cv::imwrite("R_grey.png", image_result );

  //Display the original
  cv::imshow("Original",image_original );

  //Display the result
  cv::imshow("Result", image_result );

  //Wait for a key press
  cv::waitKey(0);
}
