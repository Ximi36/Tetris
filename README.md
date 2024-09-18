# Tetris

## Opis
Tetris to klasyczna gra logiczna, w której zadaniem gracza jest układanie klocków spadających z góry ekranu w taki sposób, aby wypełnić poziome linie. Wypełnione linie znikają, a gracz zdobywa punkty. Gra kończy się, gdy klocki ułożą się w taki sposób, że nie będzie już miejsca na spadające elementy.

## Zasady gry
Klocki (zwane "tiles") pojawiają się na planszy i spadają w dół.
Gracz może przesuwać klocki w lewo, prawo, przyspieszać ich opadanie, a także obracać je.
Celem gry jest wypełnianie całych poziomych linii na planszy. Każda ukończona linia znika, a gracz zdobywa punkty.
Gra kończy się, gdy klocki dotrą do górnej krawędzi planszy.

## Sterowanie
Strzałka w lewo - przesuwa klocek w lewo.
Strzałka w prawo - przesuwa klocek w prawo.
Strzałka w górę - obraca klocek.
Strzałka w dół - przyspiesza opadanie klocka.
P - pauzuje grę.

## Punkty
Gracz zdobywa punkty za każdą usuniętą linię, przy czym im więcej linii usuniętych jednocześnie, tym więcej punktów można zdobyć. Punkty za usunięte linie liczone są według wzoru:

1 linia: 100 punktów
2 linie: 400 punktów
3 linie: 900 punktów
4 linie: 1600 punktów

## Techniczne szczegóły
Gra została napisana w języku C++ i składa się z kilku klas:

Cell: Klasa reprezentująca pojedynczą komórkę na planszy.
Board: Klasa odpowiadająca za planszę gry oraz zarządzanie komórkami.
Entity: Klasa bazowa dla poruszających się obiektów w grze.
Tiles: Klasa reprezentująca klocki o różnych kształtach (np. T, I, L, O).
Game: Główna klasa odpowiedzialna za kontrolę logiki gry, obsługę interakcji i wyświetlanie planszy.

## Wymagania
Kompilator C++ (np. g++)
System operacyjny Windows (gra korzysta z funkcji specyficznych dla konsoli Windows, takich jak SetConsoleCursorPosition)

## Autor
ximi36
