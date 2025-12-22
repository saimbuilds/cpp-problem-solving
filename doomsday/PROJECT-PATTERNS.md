# 🎮 PROJECT PATTERNS QUICK REFERENCE
## TumblePop Code Patterns for Exam

> **Why This Matters:** Exam can test project concepts in ANY FORM  
> **Focus:** Code patterns, not game logic

---

# 🔧 PARALLEL ARRAY MANAGEMENT

## The Core Pattern from Your Game

Your TumblePop used **NO structs** → Everything in parallel arrays

### Example: Ghost Enemy System
```cpp
const int MAX_GHOSTS = 8;

// Parallel arrays - SAME index = SAME ghost
float ghost_x[MAX_GHOSTS];
float ghost_y[MAX_GHOSTS];
float ghost_speed[MAX_GHOSTS];
bool ghost_movingRight[MAX_GHOSTS];
int ghost_width[MAX_GHOSTS];
int ghost_height[MAX_GHOSTS];
bool ghost_isCaptured[MAX_GHOSTS];
bool ghost_isStunned[MAX_GHOSTS];
int ghost_animFrame[MAX_GHOSTS];

// SFML sprites (not relevant for exam, but in your code)
Sprite ghost_sprites[MAX_GHOSTS];
```

### Key Pattern Rules:
1. ✅ **Same index = Same entity**
   - `ghost_x[3]` and `ghost_y[3]` belong to ghost #3
   
2. ✅ **Initialize all arrays together**
   ```cpp
   for(int i = 0; i < MAX_GHOSTS; i++) {
       ghost_x[i] = startX;
       ghost_y[i] = startY;
       ghost_speed[i] = 1.5f;
       ghost_movingRight[i] = true;
       ghost_width[i] = 45;
       ghost_height[i] = 45;
       ghost_isCaptured[i] = false;
       ghost_isStunned[i] = false;
       ghost_animFrame[i] = 0;
   }
   ```

3. ✅ **Update all arrays together**
   ```cpp
   void updateGhost(int index) {
       if(ghost_isCaptured[index]) return;  // Skip if captured
       
       // Update position
       if(ghost_movingRight[index]) {
           ghost_x[index] += ghost_speed[index];
       } else {
           ghost_x[index] -= ghost_speed[index];
       }
       
       // Update animation
       ghost_animFrame[index]++;
       if(ghost_animFrame[index] >= 4) {
           ghost_animFrame[index] = 0;
       }
   }
   ```

---

## Exam Question Type

**"Explain how to manage multiple entities without using structs"**

**Answer Template:**
```
Use parallel arrays where each array stores one property of all entities.
The same index across all arrays represents the same entity.

Example: For 5 students without struct:
- int ids[5];        // Student IDs
- char names[5][50]; // Student names
- float gpas[5];     // Student GPAs

Student 0: ids[0], names[0], gpas[0]
Student 1: ids[1], names[1], gpas[1]
...

Benefits: Simple memory layout, cache-friendly
Drawbacks: Must keep arrays synchronized
```

---

# 💥 COLLISION DETECTION PATTERNS

## Pattern 1: AABB (Axis-Aligned Bounding Box)

**Your vacuum-to-enemy collision:**
```cpp
bool checkRectCollision(float x1, float y1, int w1, int h1,
                        float x2, float y2, int w2, int h2) {
    return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2);
}
```

**Logic Breakdown:**
- `x1 < x2 + w2`: Obj1 left edge is left of Obj2 right edge
- `x1 + w1 > x2`: Obj1 right edge is right of Obj2 left edge
- Same logic for Y axis

**Visual:**
```
       x2      x2+w2
        |--------|
   x1   |  COLLISION!
    |---|--------|
       x1+w1
```

---

## Pattern 2: Distance-Based Collision

**Your vacuum range check:**
```cpp
bool isInRange(float x1, float y1, float x2, float y2, float maxRange) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float distance = sqrt(dx*dx + dy*dy);
    return distance <= maxRange;
}
```

**Key:** Pythagorean theorem: `d = √(Δx² + Δy²)`

---

## Pattern 3: 4-Point Horizontal Collision

**Your player-to-wall collision:**
```cpp
bool check_horizontal_collision(float newX, float y, int width, int height) {
    // Check 4 corners of player hitbox
    int gridX1 = newX / CELL_SIZE;
    int gridX2 = (newX + width) / CELL_SIZE;
    int gridY1 = y / CELL_SIZE;
    int gridY2 = (y + height) / CELL_SIZE;
    
    // Check if ANY corner hits a wall block
    if(level[gridY1][gridX1] == '#') return true;  // Top-left
    if(level[gridY1][gridX2] == '#') return true;  // Top-right
    if(level[gridY2][gridX1] == '#') return true;  // Bottom-left
    if(level[gridY2][gridX2] == '#') return true;  // Bottom-right
    
    return false;
}
```

**Concept:** Convert pixel coordinates to grid coordinates, check all corners

---

## Pattern 4: Ground Detection (Gravity System)

```cpp
bool isOnGround(float x, float y, int width, int height) {
    int footY = (y + height + 1) / CELL_SIZE;  // One pixel below feet
    
    // Check 3 points: left foot, center, right foot
    int leftFootX = x / CELL_SIZE;
    int centerX = (x + width/2) / CELL_SIZE;
    int rightFootX = (x + width) / CELL_SIZE;
    
    return (level[footY][leftFootX] == '#' ||
            level[footY][centerX] == '#' ||
            level[footY][rightFootX] == '#');
}
```

**Why 3 points?** Prevents falling through platforms at corners

---

# 🗺️ 2D GRID / LEVEL SYSTEM

## Coordinate Conversion Patterns

### Pixel → Grid
```cpp
int gridRow = pixelY / CELL_SIZE;
int gridCol = pixelX / CELL_SIZE;
```

### Grid → Pixel
```cpp
float pixelX = gridCol * CELL_SIZE;
float pixelY = gridRow * CELL_SIZE;
```

**Example:** CELL_SIZE = 64
- Pixel (200, 150) → Grid (3, 2)
- Grid (5, 7) → Pixel (448, 320)

---

## Level Initialization Pattern

```cpp
const int ROWS = 14;
const int COLS = 18;
char level[ROWS][COLS];

void initializeLevel() {
    // Define level layout as string
    const char* layout[] = {
        "##################",
        "#                #",
        "#  ###    ###    #",
        "#                #",
        "# ##  ####  ##   #",
        "#                #",
        //... more rows
    };
    
    // Copy to 2D array
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            level[i][j] = layout[i][j];
        }
    }
}
```

**Character meanings:**
- `'#'` = solid block (wall/platform)
- `' '` = empty space
- `'S'` = slanted platform (your Level 2 diagonal)

---

## Diagonal Platform Check

**Your slant detection logic:**
```cpp
int checkIfOnSlant(int row, int col) {
    // Diagonal pattern: row - col == 1
    // Covers rows 3-11, cols 2-11
    if(row >= 3 && row <= 11 && 
       col >= 2 && col <= 11 &&
       row - col == 1 &&
       level[row][col] == 'S') {
        return 1;  // Triggers auto-glide
    }
    return 0;
}
```

**Why `row - col == 1`?**
```
Diagonal pattern:
Row 3, Col 2  → 3-2=1 ✓
Row 4, Col 3  → 4-3=1 ✓
Row 5, Col 4  → 5-4=1 ✓
```

---

# 💾 FILE I/O PATTERNS

## Reading Text File (Leaderboard)

```cpp
void loadLeaderboard(char names[][50], int scores[], int& count) {
    ifstream file("Data/leaderboard.txt");
    count = 0;
    
    while(file >> names[count] >> scores[count]) {
        count++;
        if(count >= MAX_ENTRIES) break;
    }
    
    file.close();
}
```

**File format:**
```
PLAYER1 1500
PLAYER2 1200
PLAYER3 800
```

**Key:** `>>` operator reads space-separated values

---

## Writing Text File

```cpp
void saveLeaderboard(char names[][50], int scores[], int count) {
    ofstream file("Data/leaderboard.txt");
    
    for(int i = 0; i < count; i++) {
        file << names[i] << " " << scores[i] << endl;
    }
    
    file.close();
}
```

---

## Sorting (Bubble Sort for Leaderboard)

```cpp
void sortLeaderboard(char names[][50], int scores[], int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(scores[j] < scores[j+1]) {  // Descending order
                // Swap scores
                int tempScore = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = tempScore;
                
                // Swap names
                char tempName[50];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], tempName);
            }
        }
    }
}
```

---

# 🎯 PROJECTILE PHYSICS PATTERN

## Creation
```cpp
const int MAX_PROJECTILES = 20;

float proj_x[MAX_PROJECTILES];
float proj_y[MAX_PROJECTILES];
float proj_velocityX[MAX_PROJECTILES];
float proj_velocityY[MAX_PROJECTILES];
bool proj_active[MAX_PROJECTILES];
int proj_bounceCount[MAX_PROJECTILES];

void createProjectile(float startX, float startY, int direction) {
    // Find inactive slot
    for(int i = 0; i < MAX_PROJECTILES; i++) {
        if(!proj_active[i]) {
            proj_x[i] = startX;
            proj_y[i] = startY;
            proj_active[i] = true;
            proj_bounceCount[i] = 0;
            
            // Set velocity based on direction
            if(direction == 0) {  // Right
                proj_velocityX[i] = 15.0f;
                proj_velocityY[i] = 0;
            } else if(direction == 1) {  // Left
                proj_velocityX[i] = -15.0f;
                proj_velocityY[i] = 0;
            }
            // ... other directions
            break;
        }
    }
}
```

---

## Update with Gravity + Wall Bounce
```cpp
void updateProjectile(int index) {
    if(!proj_active[index]) return;
    
    // Apply gravity if airborne
    proj_velocityY[index] += GRAVITY;
    if(proj_velocityY[index] > MAX_FALL_SPEED) {
        proj_velocityY[index] = MAX_FALL_SPEED;
    }
    
    // Update position
    proj_x[index] += proj_velocityX[index];
    proj_y[index] += proj_velocityY[index];
    
    // Wall bounce logic
    if(proj_x[index] <= 0 || proj_x[index] >= SCREEN_WIDTH) {
        proj_velocityX[index] *= -1;  // Reverse direction
        proj_bounceCount[index]++;
        
        // Despawn after 2 bounces
        if(proj_bounceCount[index] >= 2) {
            proj_active[index] = false;
        }
    }
    
    // Ground collision
    if(isOnGround(proj_x[index], proj_y[index])) {
        proj_velocityY[index] = -10.0f;  // Bounce up
    }
}
```

---

# ⏱️ TIMING PATTERNS (Clock-Based)

**Your animation timing:**
```cpp
Clock animClock;

void updateAnimation() {
    if(animClock.getElapsedTime().asSeconds() >= 0.18f) {
        // Update frame
        currentFrame++;
        if(currentFrame >= TOTAL_FRAMES) {
            currentFrame = 0;
        }
        
        animClock.restart();
    }
}
```

**Exam equivalent (without SFML):**
```cpp
#include <ctime>

time_t lastUpdateTime = time(0);

void update() {
    time_t currentTime = time(0);
    double elapsedSeconds = difftime(currentTime, lastUpdateTime);
    
    if(elapsedSeconds >= 0.18) {
        // Update logic
        lastUpdateTime = currentTime;
    }
}
```

---

# 🎲 RANDOM NUMBER PATTERNS

**Your power-up spawn timing:**
```cpp
#include <cstdlib>
#include <ctime>

// Seed once at program start
srand(time(0));

// Generate random in range [min, max]
int randomRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Your usage:
int spawnDelay = randomRange(300, 600);  // frames
```

---

# 🔄 STATE MACHINE PATTERN

**Your game states:**
```cpp
enum GameState {  // If enums allowed, but your code used int
    MENU = 0,
    PLAYING = 1,
    VICTORY = 2,
    GAME_OVER = 3
};

int currentState = MENU;

void gameLoop() {
    while(true) {
        if(currentState == MENU) {
            handleMainMenu();
        } else if(currentState == PLAYING) {
            updateGameplay();
        } else if(currentState == VICTORY) {
            showVictoryScreen();
        } else if(currentState == GAME_OVER) {
            showGameOverScreen();
        }
    }
}
```

**Pattern:** One variable controls entire program flow

---

# 📊 COMMON EXAM QUESTIONS FROM PROJECT

## Q1: "Write a function to manage multiple objects without structs"
**Answer:** Use parallel arrays (see section 1)

---

## Q2: "Explain collision detection between two rectangles"
**Answer:** AABB algorithm (see Pattern 1)

---

## Q3: "How to convert between grid and pixel coordinates?"
**Answer:**
```cpp
Grid to Pixel: pixelX = gridCol * cellSize
Pixel to Grid: gridCol = pixelX / cellSize
```

---

## Q4: "Implement a leaderboard system with file I/O"
**Answer:** 
1. Read from file to parallel arrays
2. Sort arrays (bubble sort, keep parallel arrays synchronized)
3. Write back to file

---

## Q5: "Explain projectile physics with gravity"
**Answer:**
```cpp
1. Store velocityX and velocityY for each projectile
2. Each frame: velocityY += gravity (downward acceleration)
3. Update position: x += velocityX, y += velocityY
4. Check collisions, apply bounce logic
```

---

## Q6: "How to implement frame-independent animation?"
**Answer:** Use time-based updates
```cpp
Check elapsed time since last update
If time >= frameDelay:
    Update animation frame
    Reset timer
```

---

# ✅ KEY FORMULAS FROM YOUR PROJECT

| Concept | Formula |
|---------|---------|
| Distance | `sqrt(dx*dx + dy*dy)` |
| Grid→Pixel | `pixel = grid * cellSize` |
| Pixel→Grid | `grid = pixel / cellSize` |
| Diagonal Check | `row - col == constant` |
| AABB Collision | 4 overlap conditions (AND) |
| Random Range | `min + rand() % (max-min+1)` |

---

**END OF PROJECT PATTERNS**

**Key Takeaway:** Your 4765-line game = proof you understand:
- Array management
- Collision detection
- File I/O
- Grid systems
- Physics simulation

**Use project examples in conceptual answers!**
