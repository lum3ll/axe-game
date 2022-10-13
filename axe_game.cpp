#include "raylib.h"

int main()
{
    // Windows dimensions
    int width{1200};
    int height{800};

    // Call the function InitWindow() to create the window
    InitWindow(width, height, "Luca's Axe Game Window");

    // Circle coordinates
    int circle_x{400};
    int circle_y{400};
    int circle_radius{25};

    // Axe coordinates
    int axe_x{575};
    int axe_y{0};
    int axe_length{50};

    // Define circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y - circle_radius};

    // Define axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};
    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

    // Set target FPS to 60 and handle movements.
    SetTargetFPS(60);
    
    // Keep alive the window until X o Escape (on keyboard) is pressed
    while(WindowShouldClose() != true) 
    {
        BeginDrawing();

        // Clear background and change color
        ClearBackground(WHITE);             

        if(collision_with_axe == true)
        {
            DrawText("Game Over", 500, 400, 40, GREEN);
            DrawText("Press N and try again", 500, 600, 32, BLUE);
            if(IsKeyDown(KEY_N))
            {
                circle_x = 400;
                circle_y = 400;
                collision_with_axe = false;
            }
        } else {
            /*
            Game logic begins
            */

            // Update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // Update collision_with_axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

            // Draw a circle in the middle of the canvas
            DrawCircle(circle_x, circle_y, circle_radius, BLUE); 

            // Draw a rectangle in specific position
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            axe_y += direction;

            if(axe_y > height || axe_y < 0) 
            {
                direction = -direction;
            }

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
            
            /*
            Game logic ends
            */
        }

        EndDrawing();
    }
}