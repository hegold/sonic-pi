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

    void withSampleRelatedKeywordAndPartial_AddsSampleMatchingPartial_data()
    {
        QTest::addColumn<QString>("sampleRelatedKeyword");

        QTest::newRow("sample") << "sample";
        QTest::newRow("sample_info") << "sample_info";
        QTest::newRow("sample_duration") << "sample_duration";
        QTest::newRow("use_sample_bpm") << "use_sample_bpm";
        QTest::newRow("sample_buffer") << "sample_buffer";
        QTest::newRow("sample_loaded?") << "sample_loaded?";
        QTest::newRow("load_sample") << "load_sample";
        QTest::newRow("load_samples") << "load_samples";
    }

    void withSampleRelatedKeywordAndPartial_AddsSampleMatchingPartial()
    {
        QFETCH(QString, sampleRelatedKeyword);
        QStringList context;
        context << sampleRelatedKeyword << ":t";
        QStringList result;
        auto keywords = makeKeywordList();
        QString expectedContent(":test");
        keywords[SonicPiAPIs::Sample] << expectedContent;
        auto fxArgs = makeArgsList();
        auto synthArgs = makeArgsList();

        SonicPiAPIs::updateAutoCompletionListImpl(context, result, keywords, fxArgs, synthArgs);

        QCOMPARE(result.length(), 1);
        QCOMPARE(result.first(), expectedContent);
    }

private:

    static SonicPiAPIs::KeywordList makeKeywordList() { return SonicPiAPIs::KeywordList(); }
    static SonicPiAPIs::ArgsList makeArgsList() { return SonicPiAPIs::ArgsList(); }
};


QTEST_MAIN(TestUpdateAutoCompletionList)
#include "testautocomplete.moc"
