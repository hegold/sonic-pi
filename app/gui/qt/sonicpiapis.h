//--
// This file is part of Sonic Pi: http://sonic-pi.net
// Full project source: https://github.com/samaaron/sonic-pi
// License: https://github.com/samaaron/sonic-pi/blob/master/LICENSE.md
//
// Copyright 2013, 2014, 2015, 2016 by Sam Aaron (http://sam.aaron.name).
// All rights reserved.
//
// Permission is granted for use, copying, modification, and
// distribution of modified versions of this work as long as this
// notice is included.
//++

#include <array>
#include <Qsci/qsciabstractapis.h>
#include <QHash>

class SonicPiAPIs : public QsciAbstractAPIs
{
 public:
  enum { Func, FX, Synth, Sample, Chord, Scale, MCBlock, PlayParam, SampleParam, Tuning, Examples, NContext};

  typedef std::array<QStringList, NContext> KeywordList;
  typedef QHash<QString, QStringList> ArgsList;

  SonicPiAPIs(QsciLexer *lexer);

  void addSymbol(int context, QString sym);
  void addKeyword(int context, QString keyword);
  void addFXArgs(QString fx, QStringList args);
  void addSynthArgs(QString fx, QStringList args);

  void loadSamples(QString sample_path);


  //! \reimp
  virtual void updateAutoCompletionList(const QStringList &context,
					QStringList &list);

  virtual QStringList callTips(const QStringList &context, int commas,
			       QsciScintilla::CallTipsStyle style,
			       QList<int> &shifts);


  static void updateAutoCompletionListImpl(const QStringList& context,
                                           QStringList& list,
                                           const KeywordList& keywords,
                                           const ArgsList& fxArgs,
                                           const ArgsList& synthArgs);

 private:
  KeywordList keywords;
  ArgsList fxArgs;
  ArgsList synthArgs;
};
