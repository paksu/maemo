#include "breakoutlevelgenerator.h"

#include "tile.h"
#include <math.h>

BreakoutLevelGenerator::BreakoutLevelGenerator(const int & seed)
    : seed(seed)
{ }

void BreakoutLevelGenerator::generate_level(Breakout* bo)
{
    qsrand(seed);
    if (seed == 0) {
        for (int i = 8;i > 0;i--) {
            for (int j = 1;j < ((bo->width() - TILE_W)/60) ;j++) {
                Tile* t = new Tile(j,i,6-i/2, bo);
                bo->tiles() += t;
                bo->addItem(t);
            }
        }
        return;
    }

    QList< QList<int> > grid;
    for (int x = 0;x < ((bo->width() - TILE_W*2)/60); x++) {
        grid.append(QList<int>());
        for (int y = 0;y < 20 ;y++) {
            grid[x].append(0);
        }
    }

    for (int i = 5; i; --i) {
        switch (qrand()%3) {
            case 0:
                add_sine(grid);
                break;

            case 1:
                if (qrand() % 2)
                    add_rand(grid);
                break;

            case 2:
                add_bleed(grid);
                break;
        }
    }

    int x = 0;
    foreach (QList<int> col , grid) {
        int y = 0;
        foreach (int i , col) {
            if (i) {
                Tile* t = new Tile(x+1, y+1 , i , bo);
                bo->tiles() += t;
                bo->addItem(t);
            }
            y++;
        }
        x++;
    }
}

#include <QDebug>

void BreakoutLevelGenerator::add_sine(QList< QList<int> >& grid)
{
    qDebug() << "sine";
    for (int x = 0;x < grid.size(); x++) {
        grid[x][ (int)(::sin((qreal)x / 1.0 + qrand()) * (qrand()%6) + 8 ) ] += 1;
    }
}

void BreakoutLevelGenerator::add_rand(QList< QList<int> >& grid)
{
    qDebug() << "rand";
    int w = grid.size();
    int h = grid[0].size();
    for (int i = 0; i < 20; i++) {
        grid[qrand() % w][qrand() % h] += 1;
    }
}

void BreakoutLevelGenerator::add_bleed(QList< QList<int> >& grid)
{
    qDebug() << "bleed";
    QList< QList<int> > aux;
    int x = 0;
    foreach (QList<int> col , grid) {
        aux.append(QList<int>());
        int y = 0;
        foreach (int i , col) {
            aux[x].append(0);
            if (i ||
                (x < grid.size()-1 && grid[x+1][y]) || (x > 0 && grid[x-1][y]) ||
                (y < col.size()-1  && grid[x][y+1]) || (y > 0 && grid[x][y-1])) {
                aux[x][y] = i+1;
            }
            y++;
        }
        x++;
    }
    grid = aux;
}
