#!/bin/bash
#═══════════════════════════════════════════════════════════════════════════════
# backup_build.sh - Backup build artifacts before clean rebuild
#═══════════════════════════════════════════════════════════════════════════════

# Get script directory and project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

# Configuration
BUILD_DIR="${PROJECT_DIR}/build/Debug"
BACKUP_DIR="${PROJECT_DIR}/build_history"
PROJECT_NAME="STM32_Project"
MAX_BACKUPS=10

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}═══════════════════════════════════════════════════════════════${NC}"
echo -e "${BLUE}  STM32 Build Backup Script${NC}"
echo -e "${BLUE}═══════════════════════════════════════════════════════════════${NC}"

# Create backup directory
mkdir -p "$BACKUP_DIR"

# Check if there are files to backup
if [ -f "${BUILD_DIR}/${PROJECT_NAME}.elf" ]; then
    # Create timestamped backup folder
    TIMESTAMP=$(date +%Y%m%d_%H%M%S)
    BACKUP_SUBDIR="${BACKUP_DIR}/${TIMESTAMP}"
    mkdir -p "$BACKUP_SUBDIR"

    echo -e "${YELLOW}Backing up build artifacts...${NC}"

    # Copy all build artifacts
    for ext in elf hex bin map asm; do
        if [ -f "${BUILD_DIR}/${PROJECT_NAME}.${ext}" ]; then
            cp "${BUILD_DIR}/${PROJECT_NAME}.${ext}" "$BACKUP_SUBDIR/"
            echo -e "  ${GREEN}✓${NC} ${PROJECT_NAME}.${ext}"
        fi
    done

    # Get file size for info
    ELF_SIZE=$(ls -lh "${BACKUP_SUBDIR}/${PROJECT_NAME}.elf" 2>/dev/null | awk '{print $5}')

    echo -e "${GREEN}Backup complete: ${BACKUP_SUBDIR}${NC}"
    echo -e "  ELF size: ${ELF_SIZE}"

    # Clean old backups (keep last MAX_BACKUPS)
    BACKUP_COUNT=$(ls -1 "$BACKUP_DIR" 2>/dev/null | wc -l | tr -d ' ')
    if [ "$BACKUP_COUNT" -gt "$MAX_BACKUPS" ]; then
        echo -e "${YELLOW}Cleaning old backups (keeping last ${MAX_BACKUPS})...${NC}"
        cd "$BACKUP_DIR" && ls -1t | tail -n +$((MAX_BACKUPS + 1)) | xargs -I {} rm -rf {}
    fi
else
    echo -e "${YELLOW}No previous build found to backup${NC}"
fi

echo -e "${BLUE}═══════════════════════════════════════════════════════════════${NC}"