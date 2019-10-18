#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Util {
    unsigned int load_texture_from_file(const char* path , const std::string& directory);
    void show_mat(const std::string& matrix_name , glm::mat4& matrix);
};
#endif
