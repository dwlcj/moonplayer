#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QWidget>

class QTreeWidget;
class QTreeWidgetItem;
class DownloaderGroup;
class DownloaderItem;

class Downloader : public QWidget
{
    Q_OBJECT

signals:
    void newPlay(const QString &name, const QString &file);
    void newFile(const QString &name, const QString &file);

public:
    explicit Downloader(QWidget *parent = 0);
    inline bool hasTask(){return n_downloading != 0;}
    
public slots:
    void addTask(const QByteArray &url, const QString &filename, bool in_group, const QByteArray &danmaku = QByteArray());
    
private:
    QTreeWidget *treeWidget;
    QHash<QString, DownloaderGroup*> dir2group;
    QList<DownloaderItem*> waitings;
    int n_downloading;

private slots:
    void onFinished(QTreeWidgetItem *item, bool error);
    void onPauseButton(void);
    void onPlayButton(void);
    void onDelButton(void);
};
extern Downloader *downloader;

#endif // DOWNLOADER_H
