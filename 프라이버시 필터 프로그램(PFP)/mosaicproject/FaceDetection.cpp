#include "FaceDetection.h"
#include "MosaicImage.h"
#include "RealTimeMosaic.h"
#include <iostream>

void selectMode() {
    while (true) {
        std::cout << "모드를 선택하세요:" << std::endl;
        std::cout << "1. 이미지 파일에서 얼굴 모자이크 처리" << std::endl;
        std::cout << "2. 실시간 웹캠 얼굴 모자이크 처리" << std::endl;
        std::cout << "3. 프로그램 종료" << std::endl;

        std::string mode;
        std::cin >> mode;

        if (mode == "1") {
            processImage("C:/openCV/원본 이미지.jpg", "C:/openCV/저장 폴더");
        }
        else if (mode == "2") {
            realTimeMosaic();
        }
        else if (mode == "3") {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }
        else {
            std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
        }
    }
}
