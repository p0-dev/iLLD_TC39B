@echo off

:: ---------------------------------------------------------------------------------------
::  Cfg
:: ---------------------------------------------------------------------------------------
call %cd%\cfg.bat

:: ---------------------------------------------------------------------------------------
::  Navigation
:: ---------------------------------------------------------------------------------------
cd ../

:: ---------------------------------------------------------------------------------------
::  Build
:: ---------------------------------------------------------------------------------------
set "build_args=--build %DIR_BUILD%"
set "build_args=%build_args% -j12"
set "build_args=%build_args% --clean-first"

cmake %build_args%

:: ---------------------------------------------------------------------------------------
::  End file
:: ---------------------------------------------------------------------------------------
cd script\
