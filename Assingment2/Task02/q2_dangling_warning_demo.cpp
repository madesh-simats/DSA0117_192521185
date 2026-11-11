// Compile only to observe the compiler diagnostic. DO NOT call this function.
int& badReference() {
    int local = 42;
    return local; // Dangling reference: local dies when the function returns.
}

int main() {
    // Intentionally does not call badReference(): using its returned reference
    // would be undefined behaviour.
    return 0;
}
