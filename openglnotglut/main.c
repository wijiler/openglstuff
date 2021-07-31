#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#define GLEW_STATIC
#include <GL/glew.h>

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define MANUAL_TIME_STEP 0.1

bool program_failed = false;
bool pause = false;
double time = 0.0;
GLuint main_program = 0;
GLint main_resolution_uniform = 0;
GLint main_time_uniform = 0;


void window_size_callback(GLFWwindow* window, int width, int height)
{
    (void) window;
    glViewport(
        width / 2 - SCREEN_WIDTH / 2,
        height / 2 - SCREEN_HEIGHT / 2,
        SCREEN_WIDTH,
        SCREEN_HEIGHT);
}


    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    (void) window;
    (void) scancode;
    (void) action;
    (void) mods;

    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_F5) {
            
        } else if (key == GLFW_KEY_SPACE) {
            pause = !pause;
        } else if (key == GLFW_KEY_Q) {
            exit(1);
        }

        if (pause) {
            if (key == GLFW_KEY_LEFT) {
                time -= MANUAL_TIME_STEP;
            } else if (key == GLFW_KEY_RIGHT) {
                time += MANUAL_TIME_STEP;
            }
        }
    }
}

int main()
{
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not initialize GLFW\n");
         program_failed = true;
        exit(1);
    }


    GLFWwindow * const window = glfwCreateWindow(
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    "Sus",
                                    NULL,
                                    NULL);
    if (window == NULL) {
        fprintf(stderr, "ERROR: could not create a window.\n");
         program_failed = true;
        glfwTerminate();
        exit(1);
    }

    

    glfwMakeContextCurrent(window);

    if (GLEW_OK != glewInit()) {
        fprintf(stderr, "Could not initialize GLEW!\n");
        program_failed = true;
        exit(1);
    }

    if (!GLEW_EXT_draw_instanced) {
        fprintf(stderr, "Support for EXT_draw_instanced is required!\n");
        program_failed = true;
        exit(1);
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

            glfwSetKeyCallback(window, key_callback);
            glfwSetFramebufferSizeCallback(window, window_size_callback);

        if (!program_failed) {
                        glUniform2f(main_resolution_uniform,
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT);
            glUniform1f(main_time_uniform, time);

        }


        double prev_time;
        glfwSwapBuffers(window);
        glfwPollEvents();
                double cur_time = glfwGetTime();
        if (!pause) {
            time += cur_time - prev_time;
        }
        prev_time = cur_time;
    }


    return 0;
    }