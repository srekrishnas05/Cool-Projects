## **Hi there, I'm Sre krishna Subrahamanian, a student at Stevens Institute of Technology. I'm studying Computer Engineering!**
### Learn, Learn, Learn!!! Everyday I'm trying to learn something new and want to continue documenting my process! ###
### I've created this GitHub Repo to showcase some cool projects I've worked on, both in and out of school. ###

A few of my interests are
1. Firmware & Embedded Systems
2. Physics, Astronomy, & Math
3. Renewable Energy & Sustainability
4. AI/ML Development & Applications

---

[Here is my linkedin!](https://www.linkedin.com/in/srekrishnasubrahamanian/)

<p align="center">
  <img src="https://github.com/user-attachments/assets/989dac2b-5b20-4d05-92c8-c4d221b78c2f" width="300" height="300" /><br>
  <em>Here is a picture of me with my favorite animal!</em>
</p>

<p align="center">
  <img src="https://tour.stevens.edu/maps/UMAP_2017082365446_MINI.jpg" width="300" height="300" /><br>
  <em>Here is a picture of my university!</em>
</p>

---
Here's a little snippet you can run through your terminal!

```
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

int main() {
    const int width = 80;
    const int height = 24;
    float t = 0;

    while (true) {
        std::system("clear"); // Use "cls" on Windows

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                float dx = x - width / 2;
                float dy = y - height / 2;
                float dist = std::sqrt(dx * dx + dy * dy);
                char c = " .:-=+*#%@"[(int)(5 + 5 * std::sin(dist / 2 - t)) % 10];
                std::cout << c;
            }
            std::cout << '\n';
        }

        t += 0.1f;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}

```


