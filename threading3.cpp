// JOIN
// Once a thread is started we wait for the program by calling join() function
// Joining two times will result into program termination(Error)
// If needed we should check if the thread is joinable or not

// DETACH
// This is used to detach newly created thread from the parent thread
// Always double check before detatching a thread that it is joinable or otherwise we mau end up double detaching the it'll throw error
// If we have detached thread and main function is returning then the detached thread execution is suspended
