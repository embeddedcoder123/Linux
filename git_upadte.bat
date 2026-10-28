@echo off
cd /d "%~dp0"

git pull
if errorlevel 1 exit /b 1

git add -A

git status --short
git diff --cached --quiet
if %errorlevel%==0 (
    echo No changes to commit.
    pause
    exit /b 0
)

git commit -m "Added"
if errorlevel 1 exit /b 1

git push
pause
