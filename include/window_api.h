#ifndef WINDOW_API_H
#define WINDOW_API_H

struct PrismWindow { 
    void *window_ptr;
    int width;
    int height;
};

// Initializes Window Engine
// This is required in case the windowing engine backend requires initilization
void initialize_window_engine();

// Terminates the Window Engine
// This is required in case the windowing engine backend requires termination
// This function should ensure the clearing of all memory belonging to the windows and their management
void terminate_window_engine();

// Create prism window
int create_prism_window(int width, int height, const char *window_hint, struct PrismWindow *prism_window);

// Fetch window close flags, return 0 if false, 1 if true
int get_window_close_flag(struct PrismWindow prism_window);

// Query window for input events.
// TODO: Add callback functionality somewhow
void process_input(struct PrismWindow prism_window);

// Invoke Swap Chain
// TODO: Read up more on Vulkan swap chains? Idk man 
void invoke_swap_chain(struct PrismWindow prism_window);

// Poll window or windowing system for events
// TODO: Refine this when learning if quering events is commonly done on a per-window basis 
void poll_window_events(struct PrismWindow prism_window);

#endif // !WINDOW_API_H
