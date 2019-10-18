#include "display.h"
#include <iostream>


namespace Engine {


    Display::Display(const std::string& window_name,
const int width , const int height ):m_close(false)   {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE ,GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width  , height , window_name.c_str(), nullptr , nullptr);

        if(m_window == nullptr) {
            std::cerr << "Failed to create GLFW window.\n";
            glfwTerminate();
            exit(1);
        }

        glfwMakeContextCurrent(m_window);
        set_callbacks();


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD.\n";
            exit(1);
        }




    }

    Display::~Display() {

        glfwTerminate();

    }

    void Display::set_callbacks(bool capture_mouse) {
        
        glfwSetFramebufferSizeCallback(m_window , frambuffer_size_callback);

        if(capture_mouse)
            glfwSetInputMode(m_window , GLFW_CURSOR , GLFW_CURSOR_NORMAL);
        else
            glfwSetInputMode(m_window , GLFW_CURSOR , GLFW_CURSOR_DISABLED);

        glfwSetScrollCallback(m_window , scroll_callback);
        glfwSetCursorPosCallback(m_window , mouse_callback);

    }




    void Display::update() {

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Display::clear() {


        glClearColor(0.2f , 0.3f , 0.3f , 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }


    void Display::frambuffer_size_callback(GLFWwindow* window , int width , int height) {

        glViewport(0 , 0 , width , height);
    }

    
    void Display::mouse_callback(GLFWwindow* window , double xpos , double ypos) {
    }

    
    void Display::scroll_callback(GLFWwindow* window , double xoffset, double yoffset) {
    }


    void Display::process_input() {

        if(glfwGetKey(m_window ,GLFW_KEY_ESCAPE) == GLFW_PRESS)
            m_close = true;


    }


}

