void states(int s0, int s1, int D, int T,
            int* S0, int* S1, int* M) {

    int nextS0 = 0;
    int nextS1 = 0;

    if (D == 0) {
        // Door is open
        nextS0 = 0;
        nextS1 = 0;
    }
    else if (s0 == 0 && s1 == 0) {
        // Door was open; now closed
        nextS0 = 0;
        nextS1 = 1;
    }
    else if (T == 1) {
        // Door closed and timer started
        nextS0 = 1;
        nextS1 = 0;
    }
    else {
        // Door closed, timer stopped
        nextS0 = 0;
        nextS1 = 1;
    }

    *S0 = nextS0;
    *S1 = nextS1;
    *M = (nextS0 == 1 && nextS1 == 0);
}