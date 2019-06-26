#ifndef DISPLAY_H
#define DISPLAY_H

#include <QLabel>
#include <QString>

QString prompt_text(const QString& prompt, const QString& info, const QString& dlm=" ");
QString prompt_text(const QString& prompt, const int info, const QString& dlm=" ");
QString prompt_text(const QString& prompt, const std::string& info, const QString dlm=" ");
QString sign_str(int x);
void set_text_if_nonempty(QLabel* label, const QString& prompt, const QString& text);

#endif // DISPLAY_H
