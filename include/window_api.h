#ifndef WINDOW_API_H
#define WINDOW_API_H

struct PrismWindow { 
    void *window_ptr;
    int width;
    int height;
};

void initialize_window_engine();
void terminate_window_engine();
int create_prism_window(int width, int height, const char *window_hint, struct PrismWindow *prism_window);


#endif // !WINDOW_API_H
