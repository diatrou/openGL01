
// openGL20241020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //������� / ������ ���� ������������ ���� C++

// ���������� GLEW
#define GLEW_STATIC //������� ������� �� ����������. �� ������� ������������
#include <GL/glew.h>

// ���������� GLFW
#include <GLFW/glfw3.h>

// ���������� ���������
const GLint WIDTH = 800, HEIGHT = 600; // GLint ���� int ��� ����������� - ����������� ��������� -> int

// � ��������� MAIN ��� ��� ����� ������ � �������� ��� ������ � ��������� (game loop)
int main()
{
    // ������������ GLFW
    glfwInit();

    // ����������� ��������� ��� ��� GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  // ������ ��� ��� OpenGL 3.3 ��� ������ �������������� Shaders
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);  // �������� ����������� ������ 3.3. �� ����������� ��� 4.6
    
    // �������������� ��� ��� ����� ��������������� (CORE_PROFILE) ���� ��� ��� ����� (COMPAT_PROFILE)
    // ���� ����� �� ����������� ����������� ������� ���� glBegin ���
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // ���� ��������� ������ 3.3 ��� Core Profile, ���� ����� �� ���������� �� ����������� �� ����������� 
    // �������� ��� OpenGL
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // ���������� ��� macOS. ��� Windows ��� ��������.

    // ������� �� ��� ������� ������� �� ��������
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // ���������� ������������ GLFWwindow ��� �� �������������� ��� ��� ����������� ��� GLFW
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "���� S.A.E.K. Megarwn OpenGL", nullptr, nullptr);
    // �� ��������� ������� ����� ��� ��� ���������� ��������� ��� ������ (�������� �� �� �����)

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    // ������ �� ������ ��� �������� ���������� �� ������ ��� �������� ������� �� ���������, 
    // ��������� �� ���������� ������ ��� ���� ��� ��������� �� ����� �� ��� ��������� ��� ������
    // pixels ��� �����. ����������� �� ����������� ������.

    if (nullptr == window)
    {
        std::cout << "Window Creating Failure GLFW" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    // �� ��� �������� ���� ��������� �� �� �������� ������� �� ������������ ��� ������������. �����������
    // �� ���������� ��� �� ������������ ��������.

    // ������� ��� ����������� GLEW ��� �� ���������������� ��� ��� ����� ���������������
    glewExperimental = GL_TRUE;

    // ������������ ��� GLEW
    if (GLEW_OK != glewInit())
    {
        std::cout << "Initialization Failure GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    // ���������� ��� ����� ��� �� ����������� �� ������� (viewport)
    glViewport(0, 0, screenWidth, screenHeight);

    // ������������ ���������� (game loop)
    while (!glfwWindowShouldClose(window))
    {
        // ��������� �� ���� ������������� ���� (������������, �������)
        // ��� ������� ��� ������� ����� ����������
        glfwPollEvents();

        // ���������� / render
        // ���������� ��� colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT); // ��� ������������ �� ����� ��� �� ��������� ��� �����.

        // �������� OpenGL
        glfwSwapBuffers(window); //������ ������������ ������ �� �������
    }

    // ����������� ��� GLFW, ���������� ��� ����� ��� ���������������� ��� �����
    glfwTerminate();

    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
