@echo off

git pull
if errorlevel 1 exit /b 1



git diff --cached --quiet
if not errorlevel 1 (
    echo No changes to push.
    pause
    exit /b 0
)
git add .
git commit -m "Added"
if errorlevel 1 exit /b 1

git push
pause
