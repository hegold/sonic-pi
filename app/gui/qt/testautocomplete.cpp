#include <QtTest/QtTest>

#include "sonicpiapis.h"
#include <memory>

class TestUpdateAutoCompletionList: public QObject
{
    Q_OBJECT
private slots:

    void initTestCase()
    {

    }

    void cleanupTestCase()
    {

    }

    void withEmptyContext_ListIsEmpty()
    {
        QStringList context;
        QStringList result;
        auto keywords = makeKeywordList();
        auto fxArgs = makeArgsList();
        auto synthArgs = makeArgsList();

        SonicPiAPIs::updateAutoCompletionListImpl(context, result, keywords, fxArgs, synthArgs);

        QCOMPARE(result.length(), 0);
    }

private:

    static SonicPiAPIs::KeywordList makeKeywordList() { return SonicPiAPIs::KeywordList(); }
    static SonicPiAPIs::ArgsList makeArgsList() { return SonicPiAPIs::ArgsList(); }
};


QTEST_MAIN(TestUpdateAutoCompletionList)
#include "testautocomplete.moc"
