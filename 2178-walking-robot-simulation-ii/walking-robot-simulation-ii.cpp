class Robot {
private:
    int w, h;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    vector<string> dirs = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
    }

    void step(int num) {
        int cycle = 2 * (w + h) - 4;
        num %= cycle;

        // special case: if num == 0, direction depends on last edge
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }

        while (num--) {
            int nx = x, ny = y;

            if (dir == 0) nx++;
            else if (dir == 1) ny++;
            else if (dir == 2) nx--;
            else ny--;

            // check boundary
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn counterclockwise
                num++; // retry this step
            } else {
                x = nx;
                y = ny;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};