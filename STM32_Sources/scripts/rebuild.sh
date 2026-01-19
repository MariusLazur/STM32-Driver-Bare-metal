#!/bin/bash
#═══════════════════════════════════════════════════════════════════════════════
# rebuild.sh - Backup, clean, and rebuild the project
#═══════════════════════════════════════════════════════════════════════════════

# Get script directory and project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${BLUE}═══════════════════════════════════════════════════════════════${NC}"
echo -e "${BLUE}  STM32 Clean Rebuild with Backup${NC}"
echo -e "${BLUE}═══════════════════════════════════════════════════════════════${NC}"

# Step 1: Backup
echo -e "\n${YELLOW}[1/3] Backing up previous build...${NC}"
"$SCRIPT_DIR/backup_build.sh"

# Step 2: Clean
echo -e "\n${YELLOW}[2/3] Cleaning build directory...${NC}"
cd "$PROJECT_DIR"
rm -rf build/Debug/*
echo -e "${GREEN}✓ Build directory cleaned${NC}"

# Step 3: Reconfigure and Build
echo -e "\n${YELLOW}[3/3] Rebuilding...${NC}"
cmake --preset arm-debug
cmake --build build/Debug

if [ $? -eq 0 ]; then
    echo -e "\n${GREEN}═══════════════════════════════════════════════════════════════${NC}"
    echo -e "${GREEN}  Build successful!${NC}"
    echo -e "${GREEN}═══════════════════════════════════════════════════════════════${NC}"
else
    echo -e "\n${RED}═══════════════════════════════════════════════════════════════${NC}"
    echo -e "${RED}  Build failed!${NC}"
    echo -e "${RED}═══════════════════════════════════════════════════════════════${NC}"
    exit 1
fi