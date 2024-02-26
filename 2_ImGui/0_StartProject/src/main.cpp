#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "render.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    // Initialisierung von GLFW
    if (!glfwInit())
        return -1;

    // Erstellen eines GLFW-Fensters (Hauptfenster)
    GLFWwindow *window = glfwCreateWindow(1280, 720, "ImGui + GLFW", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // GLFW-Kontext einrichten
    glfwMakeContextCurrent(window);

    // ImGui-Kontext einrichten
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // ImGui-Stileinstellungen
    ImGui::StyleColorsDark();
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f); // Schwarzer Hintergrund für innere Fenster

    //XXX Hier beginnt das Rendern des Menüs und des Spielefensters!!!
    //XXX ***       ***         ***         ***         ***         XXX//
    //XXX XXX --- XXX --- XXX --- XXX --- XXX --- XXX --- XXX --- XXX//

    //main.cpp
    // Fensterliste erstellen ### VECTOREN ###
    WindowDataContainer WindowData1;
    MenuButtons MenuButtonsObj1;
    GameString GameStringObj1; //TODO implementiere eine neue Structur die die daten aus ChoosedWords.txt in ein std::map sichert


    // Haupt-Render-Schleife
    while (!glfwWindowShouldClose(window))
    {
        // Starten des ImGui-Frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        RenderMenuWindow(MenuButtonsObj1);
        RenderGameWindow(WindowData1, MenuButtonsObj1, GameStringObj1);
        RenderSettingWindow(MenuButtonsObj1);
        RenderVocableWindow(WindowData1, MenuButtonsObj1, GameStringObj1);
        gameVocablesApplyFunction(WindowData1, MenuButtonsObj1);
        gameVocablesAddFunction(WindowData1, MenuButtonsObj1);


        if (MenuButtonsObj1.gameExit)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        // Rendering und Events
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.25f, 0.25f, 0.25f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Aufräumarbeiten
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
