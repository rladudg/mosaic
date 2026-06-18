#ifndef CASCADE_PATHS_H
#define CASCADE_PATHS_H

#include <string>

const std::string BASE_PATH = R"(C:/opencv/build/etc/haarcascades/)";

const std::string FACE_CASCADE_PATH = BASE_PATH + "haarcascade_frontalface_alt2.xml";
const std::string PROFILE_FACE_CASCADE_PATH = BASE_PATH + "haarcascade_profileface.xml";
const std::string EYE_CASCADE_PATH = BASE_PATH + "haarcascade_eye.xml";
const std::string NOSE_CASCADE_PATH = BASE_PATH + "haarcascade_mcs_nose.xml";
const std::string MOUTH_CASCADE_PATH = BASE_PATH + "haarcascade_mcs_mouth.xml";
const std::string LEFT_EAR_CASCADE_PATH = BASE_PATH + "haarcascade_mcs_leftear.xml";
const std::string RIGHT_EAR_CASCADE_PATH = BASE_PATH + "haarcascade_mcs_rightear.xml";

#endif // CASCADE_PATHS_H