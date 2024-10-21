
// openGL20241020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //Είσοδος / Έξοδος ροής ενσωματωμένη στην C++

// Βιβλιοθήκη GLEW
#define GLEW_STATIC //Στατική σύνδεση με βιβλιοθήκη. Αν θέλουμε παραλείπουμε
#include <GL/glew.h>

// Βιβλιοθήκη GLFW
#include <GLFW/glfw3.h>

// Διαστάσεις παραθύρου
const GLint WIDTH = 800, HEIGHT = 600; // GLint αντί int για συμβατότητα - διαφορετικά συστήματα -> int

// Η συνάρτηση MAIN από την οποία ξεκινά η εφαρμογή και τρέχει η επανάληψη (game loop)
int main()
{
    // Αρχικοποίηση GLFW
    glfwInit();

    // Απαραίτητες ρυθμίσεις για την GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  // Επειδή από την OpenGL 3.3 και έπειτα χρησιμοποιούμε Shaders
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);  // ορίζουμε τουλάχιστον έκδοση 3.3. Θα δοκιμάσουμε και 4.6
    
    // Χρησιμοποιούμε τον νέο τρόπο προγραμματισμού (CORE_PROFILE) αντί για τον παλιό (COMPAT_PROFILE)
    // Καλό είναι να αποφεύγουμε παρωχημένες εντολές όπως glBegin κλπ
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Αφού επιλέξαμε έκδοση 3.3 και Core Profile, καλό είναι να ρυθμίσουμε τη συμβατότητα με μελλοντικές 
    // εκδόσεις της OpenGL
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Απαιτείται στα macOS. Στα Windows δεν πειράζει.

    // Ρύθμιση να μην αλλάζει μέγεθος το παράθυρο
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Δημιουργία αντικειμένου GLFWwindow που θα χρησιμοποιηθεί για τις συναρτήσεις της GLFW
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "ΣΑΕΚ S.A.E.K. Megarwn OpenGL", nullptr, nullptr);
    // Οι μηδενικοί δείκτες είναι για τις μεταβλητές παραθύρου και οθόνης (αργότερα θα το δούμε)

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    // Επειδή οι οθόνες που βγαίνουν μεγαλώνουν σε ίντσες και αλλάζουν πιθανώς οι αναλογίες, 
    // παίρνουμε το πραγματικό πλάτος και ύψος του παραθύρου σε σχέση με την πυκνότητα της οθόνης
    // pixels ανά ίντσα. Συμβατότητα με μελλοντικές οθόνες.

    if (nullptr == window)
    {
        std::cout << "Window Creating Failure GLFW" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    // Με την παραπάνω δομή ελέγχουμε αν το παράθυρο απέτυχε να δημιουργηθεί και τερματίζουμε. Διαφορετικά
    // το επιλέγουμε για να προχωρήσουμε παρακάτω.

    // Ρύθμιση της βιβλιοθήκης GLEW ότι θα χρησιμοποιήσουμε τον νέο τρόπο προγραμματισμού
    glewExperimental = GL_TRUE;

    // Αρχικοποίηση της GLEW
    if (GLEW_OK != glewInit())
    {
        std::cout << "Initialization Failure GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    // Καθορισμός του χώρου που θα εμφανιστούν τα γραφικά (viewport)
    glViewport(0, 0, screenWidth, screenHeight);

    // Επαναληπτική απεικόνιση (game loop)
    while (!glfwWindowShouldClose(window))
    {
        // Ελέγχουμε αν έχει ενεργοποιηθεί κάτι (πληκτρολόγιο, ποντίκι)
        // και κάνουμε την ανάλογη κλήση συνάρτησης
        glfwPollEvents();

        // Απεικόνιση / render
        // Εκκαθάριση του colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT); // Εδώ αποθηκεύεται το χρώμα που θα καθαρίσει την οθόνη.

        // Σχεδίαση OpenGL
        glfwSwapBuffers(window); //Αλλαγή προηγούμενης σκηνής με επόμενη
    }

    // Τερματισμός της GLFW, εκκαθάριση των πόρων που χρησιμοποιήθηκαν από αυτήν
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
