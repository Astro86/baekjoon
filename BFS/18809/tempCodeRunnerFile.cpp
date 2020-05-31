struct Point {
    int time = -1;
    bool green = false;
    bool red = false;

    bool isVisited() {
        if (green == true) {
            return true;
        } else if (red == true) {
            return true;
        } else {
            return false;
        }
    }

    int getTime() {
        return time;
    }
};