#include "MosaicImage.h"
#include "CascadePaths.h"
#include "mosaic.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void processImage(const std::string& imagePath, const std::string& outputFolder) {
    cv::CascadeClassifier faceCascade, profileFaceCascade;

    if (!faceCascade.load(FACE_CASCADE_PATH) ||
        !profileFaceCascade.load(PROFILE_FACE_CASCADE_PATH)) {
        std::cerr << "Cascade 파일을 로드할 수 없습니다" << std::endl;
        return;
    }

    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다." << std::endl;
        return;
    }

    cv::imshow("Original Image", img);
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    std::vector<cv::Rect> faces, profileFaces;
    faceCascade.detectMultiScale(gray, faces, 1.1, 4, 0, cv::Size(30, 30));
    profileFaceCascade.detectMultiScale(gray, profileFaces, 1.1, 4, 0, cv::Size(30, 30));

    for (const cv::Rect& face : faces) {
        mosaic(img, face, 0.1);
    }

    for (const cv::Rect& face : profileFaces) {
        mosaic(img, face, 0.1);
    }

    cv::imshow("Mosaic Image", img);

    while (true) {
        char key = (char)cv::waitKey(0);
        if (key == 27) { // ESC 키
            break;
        }
        else if (key == 's') {
            if (!fs::exists(outputFolder)) {
                fs::create_directories(outputFolder);
            }
            std::string outputPath = outputFolder + "/mosaic_image.jpg";
            cv::imwrite(outputPath, img);
            std::cout << "Image saved at: " << outputPath << std::endl;
        }
    }
    cv::destroyAllWindows();
}
