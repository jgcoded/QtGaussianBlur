#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <qimage.h>
#include <qpixmap.h>

class ImageLoader
{
public:
    ImageLoader();

    void Load(const QString& path);

    QPixmap* GetPixelMap() const;
    bool isLoaded() const;
    QImage GetImage() const;

    ~ImageLoader();

private:
    QPixmap *imagePixelMap;
    bool loaded;
};

#endif // IMAGELOADER_H
