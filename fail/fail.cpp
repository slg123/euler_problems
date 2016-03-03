#include <iostream>
#include <unistd.h>

using namespace std; 

void clear_screen();
void open_game_window();
void display(char a[3][3]); 
void play_animation();

int main() {

    clear_screen(); 
    open_game_window(); 
    play_animation(); 
    return 0;

}

void clear_screen() {
    cout << "\033[2J\033[1;1H";
}

void open_game_window() {
    cout << "this would open the game window. sdl or gl." << endl;
    cout << "or maybe not. it's sunny outside. i think i'll go for a walk instead." << endl;
}

void display(char a[3][3]) {
    int i, j;
    for (i=0; i<=2; i++) {
        for (j=0; j<=2; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void play_animation() {
    char j[3][3] = {{ 'x', 'x', 'x' },
                    { 'x', 'x', 'x' },
                    { 'x', 'x', 'x' }};

    char k[3][3] = {{ 'b', 'b', 'b' }, 
                    { 'b', 'b', 'b' },
                    { 'b', 'b', 'b' }};

    char l[3][3] = {{ 'u', 'u', 'u' }, 
                    { 'u', 'u', 'u' },
                    { 'u', 'u', 'u' }};

    char m[3][3] = {{ 'g', 'g', 'g' }, 
                    { 'g', 'g', 'g' },
                    { 'g', 'g', 'g' }};

    for (int i=0; i<3; i++) {
        clear_screen(); 
        display(j);
        sleep(1);
    }

    display(k); 
    sleep(1); 
    display(l);
    sleep(1); 
    display(m);
    sleep(1); 

    cout << "what's that spell?" << endl;
    sleep(1); 
    cout << "BUG!" << endl;
}


