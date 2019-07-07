

#ifndef _SHCOMMANDDOCK_H
#define _SHCOMMANDDOCK_H

#include <qwidget.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qdockwidget.h>


class ShCommandList : public QTextEdit {
	friend class ShCommandDock;
	friend class ShCommandContainer;

private:
	ShCommandList(QWidget *parent = 0);
	~ShCommandList();
};

class ShCommandEdit : public QLineEdit {
	friend class ShCommandDock;
	friend class ShCommandContainer;

private:
	ShCommandEdit(QWidget *parent = 0);
	~ShCommandEdit();

};

class ShCommandContainer : public QWidget {
	friend class ShCommandDock;

private:
	ShCommandList *list;
	ShCommandEdit *edit;

private:
	ShCommandContainer(QWidget *parent = 0);
	~ShCommandContainer();

protected:
	void resizeEvent(QResizeEvent *event);
	QSize sizeHint() const;
};



class ShCommandDock : public QDockWidget {

private:
	ShCommandContainer *container;

	bool menuActionChecked;
	QAction *menuAction;

public:
	ShCommandDock(QWidget *parent = 0);
	~ShCommandDock();

	void activate();
	void deactivate();

	inline QAction* getMenuAction() const { return this->menuAction; }
	inline bool isMenuActionChecked() const { return this->menuActionChecked; }

protected:
	void closeEvent(QCloseEvent *event);

	private slots:
	void menuActionClicked();

};

#endif //_COMMANDDOCK_H