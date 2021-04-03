#include <iostream>
#include <SDL.h>

using namespace std;


const int SCREEN_WIDTH = 1380;
const int SCREEN_HEIGHT = 650;
const string WINDOW_TITLE = "nonogram";

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal = false);
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();


SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren);
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y);
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h);

void refreshScreen(SDL_Window* window, SDL_Renderer* renderer,const SDL_Rect& filled_rect, const bool leftMouse = false);

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    //Nạp ảnh nền vào một biến texture 
    SDL_Texture* background = loadTexture("level1a.bmp", renderer);
    //Nạp ảnh vào một biến texture 
    SDL_Texture* image = loadTexture("pixel.bmp", renderer);
    SDL_Texture* dung = loadTexture("true.bmp", renderer);
    SDL_Texture* sai = loadTexture("false.bmp", renderer);
    SDL_Texture* heart = loadTexture("heart.bmp", renderer);
    SDL_Texture* purple = loadTexture("purple.bmp", renderer);
    //Nếu có lỗi thì giải phóng hai texture đã nạp, rồi kết thúc
    if (background == nullptr || image == nullptr || dung == nullptr || sai == nullptr || heart == nullptr|| purple == nullptr) 
    {
        SDL_DestroyTexture(background);
        SDL_DestroyTexture(image);
        SDL_DestroyTexture(dung);
        SDL_DestroyTexture(sai);
        SDL_DestroyTexture(heart);
        SDL_DestroyTexture(purple);
        quitSDL(window, renderer);
    }

    //Xoá màn hình
    SDL_RenderClear(renderer);

    //Vẽ ảnh nền vào toàn bộ cửa sổ
    renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Vẽ ảnh tại vị trí và kích cỡ mới (ảnh bị co lại cho khớp)
    for (int i = 520; i <= 730; i = i + 49)
    {
        renderTexture(heart, renderer, i, 110, 49, 49);
    }
    
    // Dùng lệnh hiển thị (đưa) hình đã vẽ ra mành hình
    SDL_RenderPresent(renderer);
    
    // Your code here
    SDL_Event e;
    


    while (true) {
        
        //SDL_Delay(0);

        // Nếu không có sự kiện gì thì tiếp tục trở về đầu vòng lặp
        if (SDL_WaitEvent(&e) == 0) continue;

        // Nếu sự kiện là kết thúc (như đóng cửa sổ) thì thoát khỏi vòng lặp
        if (e.type == SDL_QUIT) break;

        // Nếu nhấn phìm ESC thì thoát khỏi vòng lặp
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) return 0;
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.y >= 168 && e.button.y <= 218)
                {
                    if (e.button.x >= 876 && e.button.x <= 925)
                    {
                        renderTexture(dung, renderer, 876, 168, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 925 && e.button.x <= 974)
                    {
                        renderTexture(dung, renderer, 925, 168, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 974 && e.button.x <= 1072)
                    {
                        renderTexture(sai, renderer, 1023, 168, 49, 49);
                        renderTexture(purple, renderer, 716 , 110, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                   
                    if (e.button.x >= 1072 && e.button.x <= 1121)
                    {
                        renderTexture(dung, renderer, 1072, 168, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x > 1121 && e.button.x <= 1170)
                    {
                        renderTexture(dung, renderer, 1121, 168, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }
                if (e.button.y >= 219 && e.button.y <= 268)
                {
                    if (e.button.x >= 876 && e.button.x <= 925)
                    {
                        renderTexture(sai, renderer, 876, 219, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                    if (e.button.x >= 826 && e.button.x <= 876)
                    {
                        renderTexture(sai, renderer, 826, 219, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                    if (e.button.x >= 925 && e.button.x <= 974)
                    {
                        renderTexture(dung, renderer, 925, 219, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                    if (e.button.x >= 1072 && e.button.x <= 1121)
                    {
                        renderTexture(dung, renderer, 1072, 219, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                    if (e.button.x >= 1121 && e.button.x <= 1170)
                    {
                        renderTexture(sai, renderer, 1121, 219, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                    if (e.button.x >= 1219 && e.button.x <= 1268)
                    {
                        renderTexture(sai, renderer, 1219, 219, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                }

                if (e.button.y >= 269 && e.button.y <= 318)
                {
                    if (e.button.x >= 776 && e.button.x <= 826)
                    {
                        renderTexture(sai, renderer, 776, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 826 && e.button.x <= 876)
                    {
                        renderTexture(dung, renderer, 826, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 876 && e.button.x <= 924)
                    {
                        renderTexture(dung, renderer, 876, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(dung, renderer, 924, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1218)
                    {
                        renderTexture(dung, renderer, 1169, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1071 && e.button.x <= 1120)
                    {
                        renderTexture(dung, renderer, 1071, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1120 && e.button.x <= 1169)
                    {
                        renderTexture(dung, renderer, 1120, 266, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }
                if (e.button.y >= 318 && e.button.y <= 368)
                {
                    if (e.button.x >= 776 && e.button.x <= 826)
                    {
                        renderTexture(dung, renderer, 776, 313, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 826 && e.button.x <= 876)
                    {
                        renderTexture(dung, renderer, 826, 313, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(sai, renderer, 924, 313, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1120 && e.button.x <= 1169)
                    {
                        renderTexture(sai, renderer, 1120, 313, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1219)
                    {
                        renderTexture(dung, renderer, 1169, 313, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1219 && e.button.x <= 1269)
                    {
                        renderTexture(dung, renderer, 1219, 313, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }

                if (e.button.y >= 368 && e.button.y <= 417)
                {
                    if (e.button.x >= 776 && e.button.x <= 826)
                    {
                        renderTexture(dung, renderer, 776, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 826 && e.button.x <= 875)
                    {
                        renderTexture(dung, renderer, 826, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 875 && e.button.x <= 924)
                    {
                        renderTexture(sai, renderer, 875, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(sai, renderer, 924, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 973 && e.button.x <= 1022)
                    {
                        renderTexture(dung, renderer, 973, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1022 && e.button.x <= 1071)
                    {
                        renderTexture(dung, renderer, 1022, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1218)
                    {
                        renderTexture(dung, renderer, 1169, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1218 && e.button.x <= 1267)
                    {
                        renderTexture(dung, renderer, 1218, 362, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }

                if (e.button.y >= 417 && e.button.y <= 466)
                {
                    if (e.button.x >= 826 && e.button.x <= 875)
                    {
                        renderTexture(dung, renderer, 826, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 875 && e.button.x <= 924)
                    {
                        renderTexture(dung, renderer, 875, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(dung, renderer, 924, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 973 && e.button.x <= 1022)
                    {
                        renderTexture(dung, renderer, 973, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1022 && e.button.x <= 1071)
                    {
                        renderTexture(dung, renderer, 1022, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1071 && e.button.x <= 1120)
                    {
                        renderTexture(dung, renderer, 1071, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1120 && e.button.x <= 1169)
                    {
                        renderTexture(dung, renderer, 1120, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1219)
                    {
                        renderTexture(dung, renderer, 1169, 408, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }

                if (e.button.y >= 467 && e.button.y <= 516)
                {
                    if (e.button.x >= 826 && e.button.x <= 875)
                    {
                        renderTexture(sai, renderer, 826, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 875 && e.button.x <= 924)
                    {
                        renderTexture(dung, renderer, 875, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 973 && e.button.x <= 1022)
                    {
                        renderTexture(sai, renderer, 973, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1071 && e.button.x <= 1120)
                    {
                        renderTexture(sai, renderer, 1071, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1120 && e.button.x <= 1169)
                    {
                        renderTexture(dung, renderer, 1120, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1219)
                    {
                        renderTexture(sai, renderer, 1169, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1219 && e.button.x <= 1268)
                    {
                        renderTexture(sai, renderer, 1219, 457, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }

                if (e.button.y >= 516 && e.button.y <= 565)
                {
                    if (e.button.x >= 776 && e.button.x <= 826)
                    {
                        renderTexture(sai, renderer, 776, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 875 && e.button.x <= 924)
                    {
                        renderTexture(dung, renderer, 875, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(dung, renderer, 924, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 973 && e.button.x <= 1022)
                    {
                        renderTexture(sai, renderer, 973, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1022 && e.button.x <= 1071)
                    {
                        renderTexture(sai, renderer, 1022, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1071 && e.button.x <= 1120)
                    {
                        renderTexture(dung, renderer, 1071, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1120 && e.button.x <= 1169)
                    {
                        renderTexture(dung, renderer, 1120, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1219)
                    {
                        renderTexture(sai, renderer, 1169, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1219 && e.button.x <= 1268)
                    {
                        renderTexture(sai, renderer, 1219, 504, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }

                if (e.button.y >= 565 && e.button.y <= 614)
                {
                    if (e.button.x >= 776 && e.button.x <= 826)
                    {
                        renderTexture(sai, renderer, 776, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 875 && e.button.x <= 924)
                    {
                        renderTexture(dung, renderer, 875, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(dung, renderer, 924, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1022 && e.button.x <= 1071)
                    {
                        renderTexture(sai, renderer, 1022, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1071 && e.button.x <= 1120)
                    {
                        renderTexture(dung, renderer, 1071, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1120 && e.button.x <= 1169)
                    {
                        renderTexture(dung, renderer, 1120, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1169 && e.button.x <= 1219)
                    {
                        renderTexture(sai, renderer, 1169, 553, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                }

                if (e.button.y >= 614 && e.button.y <= 663)
                {
                    if (e.button.x >= 924 && e.button.x <= 973)
                    {
                        renderTexture(dung, renderer, 924, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 973 && e.button.x <= 1022)
                    {
                        renderTexture(sai, renderer, 973, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1022 && e.button.x <= 1071)
                    {
                        renderTexture(sai, renderer, 1022, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1071 && e.button.x <= 1120)
                    {
                        renderTexture(dung, renderer, 1071, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 1219 && e.button.x <= 1268)
                    {
                        renderTexture(sai, renderer, 1219, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 776 && e.button.x <= 826)
                    {
                        renderTexture(sai, renderer, 776, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }

                    if (e.button.x >= 826 && e.button.x <= 911)
                    {
                        renderTexture(sai, renderer, 826, 602, 49, 49);
                        SDL_RenderPresent(renderer);
                    }
                }
            }
        }
    }

    waitUntilKeyPressed();

    //Giải phóng 2 biến texture đã dùng
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(image);
    SDL_DestroyTexture(dung);
    SDL_DestroyTexture(sai);
    SDL_DestroyTexture(heart);
    SDL_DestroyTexture(purple);
    
    quitSDL(window, renderer);
    return 0;
}

SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren)
{
    //Khởi tạo là nullptr để tránh lỗi 'dangling pointer'
    SDL_Texture* texture = nullptr;
    //Nạp ảnh từ tên file (với đường dẫn)
    SDL_Surface* loadedImage = SDL_LoadBMP(file.c_str());
    //Nếu không có lỗi, chuyển đổi về dạng texture and và trả về
    if (loadedImage != nullptr) {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        //Đảm bảo việc chuyển đổi không có lỗi
        if (texture == nullptr) {
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    }
    else {
        logSDLError(std::cout, "LoadBMP");
    }
    return texture;
}

/**
* Vẽ một SDL_Texture lên một SDL_Renderer tại toạ độ (x, y), trong khi
* giữ nguyên chiều rộng và cao của ảnh
* @param tex: texture nguồn chúng ta muốn vẽ ra
* @param ren: thiết bị renderer chúng ta muốn vẽ vào
* @param x: hoành độ
* @param y: tung độ
*/
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y)
{
    //Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Truy vẫn texture để lấy chiều rộng và cao (vào chiều rộng và cao tương ứng của hình chữ nhật đích)
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    //Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
* Vẽ một SDL_Texture lên một SDL_Renderer tại toạ độ (x, y), với
* chiều rộng và cao mới
* @param tex: texture nguồn chúng ta muốn vẽ ra
* @param ren: thiết bị renderer chúng ta muốn vẽ vào
* @param x: hoành độ
* @param y: tung độ
* @param w: chiều rộng (mới)
* @param h: độ cao (mới)
*/
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int w, int h)
{
    //Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    //Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
    //(ảnh sẽ co dãn cho khớp với kích cỡ mới)
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

// Xoá và vẽ lại toàn bộ màn hình với 1 hình chữ nhật
void refreshScreen(SDL_Window* window, SDL_Renderer* renderer,
    const SDL_Rect& filled_rect, const bool leftMouse)
{
  

    // Vẽ hình chữ nhật với màu tuỳ thuộc nút chuột trái hay phải được nhấn
    if (leftMouse)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
    else
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);   // green
    SDL_RenderFillRect(renderer, &filled_rect);

    // Dùng lệnh hiển thị (đưa) hình đã vẽ ra mành hình
   //Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);
    
}











//hàm chung 
void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, 
    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}