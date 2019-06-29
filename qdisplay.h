#ifndef DISPLAY_H
#define DISPLAY_H

#include <QLabel>
#include <QString>

QString prompt_text(const QString& prompt, const QString& info, const QString& dlm=" ");
QString prompt_text(const QString& prompt, const int info, const QString& dlm=" ");
QString prompt_text(const QString& prompt, const std::string& info, const QString& dlm=" ");
QString sign_str(int x);
QString yn_qstring(bool b);
QString bold(const QString& qs);
void set_text_none_empty(QLabel* label, const QString& prompt, const QString& text);
void set_text_hide_empty(QLabel* label, const QString& prompt, const QString& text);

#endif // DISPLAY_H
