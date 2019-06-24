#ifndef QHELPERS_H
#define QHELPERS_H

#include <string>
#include <QString>


QString prompt_text(const QString& prompt, const QString& info, const QString& dlm=" ");
QString prompt_text(const QString& prompt, const int info, const QString& dlm=" ");
QString prompt_text(const QString& prompt, const std::string& info, const QString dlm=" ");

#endif // QHELPERS_H
