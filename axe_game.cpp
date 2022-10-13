#include "raylib.h"

int main()
{
    // Windows dimensions
    int width{1200};
    int height{800};

    // Call the function InitWindow() to create the window
    InitWindow(width, height, "Luca's Game Window");

    // Circle coordinates
    int circle_x{600};
    int circle_y{400};

    // Set target FPS to 60 and handle movements.
    SetTargetFPS(60);
    
    // Keep alive the window until X o Escape (on keyboard) is pressed
    while(WindowShouldClose() != true) 
    {
        BeginDrawing();
        // Clear background and change color
        ClearBackground(WHITE);             

        // Game logic begins

        // Draw a circle in the middle of the canvas
        DrawCircle(circle_x, circle_y, 25, BLUE); 

        // Check if key D is pressed to move circle to the right
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }    

        // Check if key A is pressed to move circle to the left
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }
        
        // Game login ends
        EndDrawing();
    }
}