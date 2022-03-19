#include "common.h"
#include "Image.h"
#include "Player.h"

#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <fstream>

constexpr GLsizei WINDOW_WIDTH = 512, WINDOW_HEIGHT = 512;
constexpr int ROOM_SIZE = 8;

static Image *room_tiles[] = {
    new Image("../resources/hole(64x64).png"), // 0 ' '
    new Image("../resources/wall_mid(64x64).png"), // 1 '#'
    new Image("../resources/wall_corner_front_left(64x64).png"), // 2 '{'
    new Image("../resources/wall_corner_front_right(64x64).png"), // 3 '}'
    new Image("../resources/wall_top_mid(64x64).png"), // 4 '-'
    new Image("../resources/wall_side_mid_left(64x64).png"), // 5 '<'
    new Image("../resources/wall_corner_bottom_left(64x64).png"), // 6 '['
    new Image("../resources/wall_corner_top_left(64x64).png"), // 7 '('
    new Image("../resources/wall_side_mid_right(64x64).png"), // 8 '>'
    new Image("../resources/wall_corner_bottom_right(64x64).png"), // 9 ']'
    new Image("../resources/wall_corner_top_right(64x64).png"), // 10 ')'
    new Image("../resources/floor_1(64x64).png"), // 11 '.'
    new Image("../resources/characters(64x64).png"), // 12 '@'
    new Image("../resources/floor_ladder(64x64).png"), // 13 'x'
    new Image("../resources/trap(64x64).png"), // 14 '!'
    new Image("../resources/win.png"), // 15 W
    new Image("../resources/game_over.png"), // 16 R
    new Image("../resources/floor_ladder(64x64).png"), // 17 Q
};

enum image_code {
  HOLE = ' ',
  WALL_MID = '#',
  WALL_CORNER_FRONT_LEFT = '{',
  WALL_CORNER_FRONT_RIGHT = '}',
  WALL_TOP_MID = '-',
  WALL_SIDE_MID_LEFT = '<',
  WALL_CORNER_BOTTOM_LEFT = '[',
  WALL_CORNER_TOP_LEFT = '(',
  WALL_SIDE_MID_RIGHT = '>',
  WALL_CORNER_BOTTOM_RIGHT = ']',
  WALL_CORNER_TOP_RIGHT = ')',
  FLOOR = '.',
  PLAYER = '@',
  EXIT = 'x',
  TRAP = '!',
  WIN = 'W',
  LOSE = 'R',
  FINISH = 'Q'
};

Image &GetTile(image_code code) {
  switch (code) {
    case HOLE:
      return *room_tiles[0];
    case WALL_MID:
      return *room_tiles[1];
    case WALL_CORNER_FRONT_LEFT:
      return *room_tiles[2];
    case WALL_CORNER_FRONT_RIGHT:
      return *room_tiles[3];
    case WALL_TOP_MID:
      return *room_tiles[4];
    case WALL_SIDE_MID_LEFT:
      return *room_tiles[5];
    case WALL_CORNER_BOTTOM_LEFT:
      return *room_tiles[6];
    case WALL_CORNER_TOP_LEFT:
      return *room_tiles[7];
    case WALL_SIDE_MID_RIGHT:
      return *room_tiles[8];
    case WALL_CORNER_BOTTOM_RIGHT:
      return *room_tiles[9];
    case WALL_CORNER_TOP_RIGHT:
      return *room_tiles[10];
    case FLOOR:
      return *room_tiles[11];
    case PLAYER:
      return *room_tiles[12];
    case EXIT:
      return *room_tiles[13];
    case TRAP:
      return *room_tiles[14];
    case WIN:
      return *room_tiles[15];
    case LOSE:
      return *room_tiles[16];
    case FINISH:
      return *room_tiles[17];
  }
}

struct InputState {
  bool keys[1024]{}; //массив состояний кнопок - нажата/не нажата
  GLfloat lastX = 400, lastY = 300; //исходное положение мыши
  bool firstMouse = true;
  bool captureMouse = true;  // Мышка захвачена нашим приложением или нет?
  bool capturedMouseJustNow = false;
} static Input;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

void OnKeyboardPressed(GLFWwindow *window, int key, int scancode, int action, int mode) {
  switch (key) {
    case GLFW_KEY_ESCAPE:
      if (action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
      break;
    case GLFW_KEY_1:glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
      break;
    case GLFW_KEY_2:glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
      break;
    default:
      if (action == GLFW_PRESS)
        Input.keys[key] = true;
      else if (action == GLFW_RELEASE)
        Input.keys[key] = false;
  }
}

void processPlayerMovement(Player &player) {
  if (Input.keys[GLFW_KEY_W])
    player.ProcessInput(MovementDir::UP, deltaTime);
  else if (Input.keys[GLFW_KEY_S])
    player.ProcessInput(MovementDir::DOWN, deltaTime);

  if (Input.keys[GLFW_KEY_A])
    player.ProcessInput(MovementDir::LEFT, deltaTime);
  else if (Input.keys[GLFW_KEY_D])
    player.ProcessInput(MovementDir::RIGHT, deltaTime);
}






//***************************************************
// MOUSE EVENTS

void OnMouseButtonClicked(GLFWwindow *window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    Input.captureMouse = !Input.captureMouse;

  if (Input.captureMouse) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    Input.capturedMouseJustNow = true;
  } else
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

}

void OnMouseMove(GLFWwindow *window, double xpos, double ypos) {
  if (Input.firstMouse) {
    Input.lastX = float(xpos);
    Input.lastY = float(ypos);
    Input.firstMouse = false;
  }

  GLfloat xoffset = float(xpos) - Input.lastX;
  GLfloat yoffset = Input.lastY - float(ypos);

  Input.lastX = float(xpos);
  Input.lastY = float(ypos);
}

void OnMouseScroll(GLFWwindow *window, double xoffset, double yoffset) {
  // ...
}

// MOUSE EVENTS END
//***************************************************





int initGL() {
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    return -1;
  }

  std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  std::cout << "Controls: " << std::endl;
  std::cout << "press right mouse button to capture/release mouse cursor  " << std::endl;
  std::cout << "W, A, S, D - movement  " << std::endl;
  std::cout << "C - hint  " << std::endl;
  std::cout << "press ESC to exit" << std::endl;

  return 0;
}

void GetMap(const std::string &path, std::vector<std::string> &map) {
  std::ifstream input_fd;
  input_fd.open(path.c_str());

  char ch;
  int n = 0;
  map.emplace_back();
  while (input_fd.get(ch)) {
    if (ch == '\n') {
      map.emplace_back();
      ++n;
    } else {
      map[n].push_back(ch);
    }
  }
}

void Render(Point pos, Image &screen, const Image &sprite) {
  for (int i = 0; i < sprite.Height(); i++) {
    for (int j = 0; j < sprite.Width(); j++) {
      int x = j + pos.x;
      int y = i + pos.y;
      if (
          (0 <= x && x < screen.Width()) &&
              (0 <= y && y < screen.Height())
          ) {
        screen.PutPixel(
            j + pos.x,
            i + pos.y,
            sprite.GetPixel(j, i)
        );
      }
    }
  }
}


Pixel AlphaBlending(Pixel src, Pixel dst) {
  double src_alpha = src.a / 255.0;
  double dst_alpha = dst.a / 255.0;

  return Pixel{
      uint8_t(src.r * src_alpha + dst.r * (1.0 - src_alpha)),
      uint8_t(src.g * src_alpha + dst.g * (1.0 - src_alpha)),
      uint8_t(src.b * src_alpha + dst.b * (1.0 - src_alpha)),
      uint8_t(255.0 - (1.0 - dst_alpha) * (1.0 - src_alpha) * 255.0)
  };
}

void BlendedRender(Point pos, Image &screen, const Image &sprite) {
  for (int i = 0; i < sprite.Height(); i++) {
    for (int j = 0; j < sprite.Width(); j++) {
      int x = j + pos.x;
      int y = i + pos.y;
      if (
          (0 <= x && x < screen.Width()) &&
              (0 <= y && y < screen.Height())
          ) {
        screen.PutPixel(
            j + pos.x,
            i + pos.y,
             AlphaBlending(sprite.GetPixel(j, i), screen.GetPixel(x, y))
        );
      }
    }
  }
}

Image GetBlendedTile(int i, int j, const std::vector<std::string> &room) {
  Image tile(WINDOW_WIDTH, WINDOW_HEIGHT, 4);
  for (int k = 0; k < tileSize; k++) {
    for (int l = 0; l < tileSize; l++) {
      tile.PutPixel(l, k, AlphaBlending(
          GetTile(image_code(room[i][j])).GetPixel(l, k),
          GetTile(image_code('.')).GetPixel(l, k)
          )
      )
    }
  }
  return tile;
}

void RenderRoom(Image &screen, const std::vector<std::string> &room) {
  for (int i = 0; i < room.size(); i++) {
    for (int j = 0; j < room[i].size(); j++) {
      if (
          (room[i][j] == '[') || (room[i][j] == ']') ||
          (room[i][j] == '<') || (room[i][j] == '>') ||
          (room[i][j] == '-')) {
        Render({j * tileSize, i * tileSize}, screen, GetBlendedTile(i, j, room));
      } else
          Render({j * tileSize, i * tileSize}, screen, GetTile(image_code(room[i][j])));
    }
  }
}


struct Rule {
  Point pos;
  MovementDir dir;
};


enum CollisionType {
  WALL,
  EMPTY,
  ENDGAME,
};

struct Collision {
  Point pos;
  Point size;
  CollisionType type;
};

std::vector<Rule> GetRoom(const std::string &path, std::vector<std::string> &room, std::vector<Collision> &colls) {
  std::vector<Rule> rules;

  GetMap(path, room);

  for (int i = 0; i < room.size(); i++) {
    for (int j = 0; j < room[i].size(); j++) {
      if (room[i][j] == 'x') {
        Rule rl{};
        rl.pos = {j * tileSize, i * tileSize};
        if (i >= j) { // LEFT DOWN
          if (i < 7 - j) { // LEFT
            rl.dir = MovementDir::LEFT;
          } else { // DOWN
            rl.dir = MovementDir::DOWN;
          }
        } else { // RIGHT UP
          if (i < 7 - j) { // UP
            rl.dir = MovementDir::UP;
          } else {
            rl.dir = MovementDir::RIGHT;
          }
        }
        rules.push_back(rl);
      } else if (
          (room[i][j] == '#') || (room[i][j] == '-') ||
              (room[i][j] == '#') || (room[i][j] == '<') ||
              (room[i][j] == '>')) {
        if ( room[i][j] == '<') {
          colls.push_back(Collision{
            {j * tileSize, i * tileSize},
            {32, tileSize},
            CollisionType::WALL
          });
        } else if (room[i][j] == '>') {
          colls.push_back(Collision{
            {j * tileSize + 32, i * tileSize},
            {32, tileSize},
            CollisionType::WALL
          });
        } else if (room[i][j] == '-') {
          colls.push_back(Collision{
            {j * tileSize, i * tileSize + 32},
            {tileSize, 32},
            CollisionType::WALL
          });
        } else {
          colls.push_back(Collision{
            {j * tileSize, i * tileSize},
            {tileSize, tileSize},
            CollisionType::WALL
          });
        }
      } else if (room[i][j] == ' ') {
        colls.push_back(Collision{
            {j * tileSize, i * tileSize},
            {tileSize, tileSize},
            CollisionType::EMPTY
        });
      } else if (room[i][j] == 'Q') {
        colls.push_back(Collision{
            {j * tileSize, i * tileSize},
            {tileSize, tileSize},
            CollisionType::ENDGAME
        });
      }
    }
  }
  return rules;
}

int main(int argc, char **argv) {
  if (!glfwInit())
    return -1;

//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "task1 base project", nullptr, nullptr);
  if (window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, OnKeyboardPressed);
  glfwSetCursorPosCallback(window, OnMouseMove);
  glfwSetMouseButtonCallback(window, OnMouseButtonClicked);
  glfwSetScrollCallback(window, OnMouseScroll);

  if (initGL() != 0)
    return -1;

  //Reset any OpenGL errors which could be present for some reason
  GLenum gl_error = glGetError();
  while (gl_error != GL_NO_ERROR)
    gl_error = glGetError();

  Point starting_pos{.x = WINDOW_WIDTH / 2, .y = WINDOW_HEIGHT / 2};
  Player player{starting_pos};

  Image screenBuffer(WINDOW_WIDTH, WINDOW_HEIGHT, 4);

  std::vector<std::string> path = {
      "../resources/room_A.txt", // A
      "../resources/room_B.txt", // B
      "../resources/room_C.txt", // C
      "../resources/room_D.txt", // D
      "../resources/room_E.txt", // E
      "../resources/room_F.txt", // F
      "../resources/room_G.txt", // G
      "../resources/room_H.txt", // H
      "../resources/room_I.txt", // I
      "../resources/room_J.txt", // J
      "../resources/room_K.txt", // K
      "../resources/room_L.txt", // L
      "../resources/room_M.txt", // M
      "../resources/room_N.txt", // N
      "../resources/room_O.txt", // O
      "../resources/room_P.txt", // P
      "../resources/win.txt", // W
      "../resources/lose.txt" // R
  };
  std::vector<std::vector<Rule>> rules(path.size());
  std::vector<std::vector<Collision>> collisions(path.size());

  std::vector<Image *> background(path.size());
  for (int i = 0 ; i < path.size() ; i++) {
    std::vector<std::string> room;
    rules[i] = GetRoom(path[i], room, collisions[i]);
    background[i] = new Image(WINDOW_WIDTH, WINDOW_HEIGHT, 4);
    RenderRoom(*background[i], room);
  }

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  GL_CHECK_ERRORS;
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  GL_CHECK_ERRORS;

  std::vector<std::string> maze;
  Point current_room{0, 0}; // start room
  GetMap("../resources/maze.txt", maze);

  bool player_visible = true;
  auto hint = Image("../resources/hint.png");
  float hint_time = 1.0f;
  float current_time = 0.0f;
  bool show_hint = false;
  //game loop
  while (!glfwWindowShouldClose(window)) {
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glfwPollEvents();

    // =========================================

    int index = maze[current_room.y][current_room.x] - 'A';
    Render({0, 0}, screenBuffer, *background[index]);

    processPlayerMovement(player);

    auto coll = collisions[index];
    for (int i = 0; i < coll.size(); i++) {
      if (player.isInside(coll[i].pos, coll[i].size)) {
        switch (coll[i].type) {
          case WALL:
            player.Reset();
            break;
          case EMPTY:
            current_room = {5, 3};
            player_visible = false;
            break;
          case ENDGAME:
            current_room = {4, 3};
            player_visible = false;
            break;
        }
      }
    }

    if (player_visible)
      player.Draw(screenBuffer);

    auto rule = rules[index];
    for (int i = 0; i < rule.size(); i++) {
      if (player.isInside(rule[i].pos, {tileSize, tileSize/2})) {
        switch (rule[i].dir) {
          case MovementDir::UP:
            current_room.y -= 1;
            player = Player(starting_pos);
            break;
          case MovementDir::DOWN:
            current_room.y += 1;
            player = Player(starting_pos);
            break;
          case MovementDir::LEFT:
            current_room.x -= 1;
            player = Player(starting_pos);
            break;
          case MovementDir::RIGHT:
            current_room.x += 1;
            player = Player(starting_pos);
            break;
        }
        break;
      }
    }

    if (Input.keys[GLFW_KEY_C]) {
      current_time = 0.0f;
      show_hint = true;
    }
    current_time += deltaTime;
    if (current_time > hint_time) show_hint = false;
    if (show_hint) BlendedRender({0, 0}, screenBuffer, hint);

    // ===============================================

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GL_CHECK_ERRORS;
    auto flipped = screenBuffer.flip();
    glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, flipped);
    GL_CHECK_ERRORS;

    delete[] flipped;
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}
