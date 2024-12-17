# Einführung in CMake mit FetchContent

Dieses Projekt demonstriert, wie man **CMake** mit der **FetchContent**-Funktion verwendet, um externe Bibliotheken einzubinden. Das Beispielprojekt lädt die Bibliothek **CLI11** automatisch herunter und baut sie, falls sie noch nicht lokal verfügbar ist.

---

## Projektbeschreibung

### CMake-Konfigurationsdatei (`CMakeLists.txt`)

```cmake
cmake_minimum_required(VERSION 3.13)

project(
    Shoutout_from_Fetchcontent            # Projektname
    VERSION 1.0                           # Projektversion
    LANGUAGES CXX                         # Programmiersprache: C++
    DESCRIPTION "This shouts out ;)"      # Projektbeschreibung
    HOMEPAGE_URL "http://vorlesung.nabla-b.engineering" # Projekt-URL
)

# FetchContent für externe Abhängigkeiten einbinden
include(FetchContent)

# Überprüfen, ob die Bibliothek CLI11 bereits vorhanden ist
find_package(CLI11 2 QUIET)
if(NOT CLI11_FOUND)
    # Wenn nicht gefunden, die Bibliothek mit FetchContent deklarieren
    fetchcontent_declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11  # GitHub-Repository von CLI11
        GIT_TAG main                                     # Branch oder Tag des Repos
    )
    fetchcontent_makeavailable(CLI11)  # Lade und baue CLI11
endif()

# Erstelle das ausführbare Programm und binde CLI11 ein
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} CLI11::CLI11)
```

## Erklärung der Datei

### `cmake_minimum_required`
Definiert die minimale Version von CMake, die benötigt wird (hier 3.13 oder neuer).

### `project`
- Initialisiert das Projekt mit einem Namen, einer Version, einer Beschreibung und einer Homepage-URL.  
- Das Projekt verwendet **C++** als Programmiersprache.

### `include(FetchContent)`
Aktiviert das **FetchContent-Modul** von CMake, das es ermöglicht, externe Bibliotheken direkt aus einem Repository zu laden und zu bauen.

### `find_package(CLI11 2 QUIET)`
- Versucht, die Bibliothek **CLI11** in Version 2 zu finden.  
- Die Option `QUIET` unterdrückt Fehlermeldungen, falls die Bibliothek nicht gefunden wird.

### `if(NOT CLI11_FOUND)`
- Prüft, ob **CLI11** nicht gefunden wurde.  
- Falls die Bibliothek fehlt, wird sie mit **FetchContent** heruntergeladen und verfügbar gemacht.

### `fetchcontent_declare`
- Deklariert, woher die Bibliothek zu holen ist (hier von [CLI11 auf GitHub](https://github.com/CLIUtils/CLI11)).  
- Mit `GIT_TAG` wird festgelegt, welcher Branch oder Tag verwendet wird (hier `main`).

### `fetchcontent_makeavailable(CLI11)`
Lädt die deklarierte Bibliothek herunter und fügt sie zum Build-System hinzu.

### `add_executable`
- Erstellt das ausführbare Programm mit dem Namen des Projekts.  
- Erwartet, dass der Quellcode in `src/main.cpp` liegt.

### `target_link_libraries`
Verlinkt die Bibliothek **CLI11** mit dem erstellten Programm.

---

## Verzeichnisstruktur

Dein Projekt sollte folgende Struktur haben:

Shoutout_from_Fetchcontent/ 
│-- CMakeLists.txt # CMake-Konfigurationsdatei 
│-- src/ 
│ └── main.cpp # Quellcode für dein Hauptprogramm

---

## Voraussetzungen
* CMake in Version 3.13 oder neuer
* Ein C++-Compiler (z.B. GCC, Clang oder MSVC)
* Internetzugang, um die CLI11-Bibliothek herunterzuladen

---

## Bauen des Projekts
Führe die folgenden Schritte aus, um das Projekt zu bauen:

```bash
# Erstelle ein Verzeichnis für die Builds
mkdir build
cd build

# Führe CMake aus, um das Projekt zu konfigurieren
cmake ..

# Baue das Projekt
cmake --build .
```

---

## Ergebnis
Nach dem erfolgreichen Build wird ein ausführbares Programm erstellt, das CLI11 verwendet. Dieses Beispiel zeigt, wie einfach sich externe Bibliotheken mithilfe von CMake FetchContent in ein Projekt integrieren lassen.

---

## Weitere Informationen

- [CMake-Dokumentation](https://cmake.org/documentation/)  
- [CLI11 GitHub-Seite](https://github.com/CLIUtils/CLI11)  
- [CMake FetchContent Dokumentation](https://cmake.org/cmake/help/latest/module/FetchContent.html)