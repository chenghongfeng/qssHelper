#include "path.h"

#include <QApplication>
#include <QDir>

QString Path::cdUp(const QString &folder)
{
    QDir tempFolder(folder);
    if (!tempFolder.cdUp())
    {
        return folder;
    }
    return tempFolder.absolutePath();
}

Path::Path()
{
    m_exeDir = QApplication::applicationDirPath();
    m_appDir = cdUp(m_exeDir);
    m_dataDir = QString("%1/Data").arg(m_appDir);
    m_configFilePath = QString("%1/config.ini").arg(m_dataDir);
}
