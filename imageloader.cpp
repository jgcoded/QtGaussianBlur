#include "imageloader.h"
#include <qimage.h>
#include <qpixmap.h>
#include <qmessagebox.h>

ImageLoader::ImageLoader()
{
    imagePixelMap = new QPixmap;
    loaded = false;
}

void ImageLoader::Load(const QString& path)
{
    if (!imagePixelMap->load(path))
    {
        loaded = false;
        QMessageBox::critical(0, "Failed to load image", path);
        return;
    }

    loaded = true;
}

QPixmap* ImageLoader::GetPixelMap() const
{
    return imagePixelMap;
}

bool ImageLoader::isLoaded() const
{
    return loaded;
}

QImage ImageLoader::GetImage() const
{
    return imagePixelMap->toImage();
}

ImageLoader::~ImageLoader()
{
    if (imagePixelMap != NULL)
        delete imagePixelMap;
}
