#include "FileZilla.h"

CDirectoryListing::CDirectoryListing()
{
	m_pEntries = 0;
	m_entryCount = 0;
	m_hasUnsureEntries = false;
	m_failed = false;
}

CDirectoryListing::~CDirectoryListing()
{
	delete [] m_pEntries;
}

CDirectoryListing& CDirectoryListing::operator=(const CDirectoryListing &a)
{
	if (&a == this)
		return *this;

	if (m_pEntries)
		delete [] m_pEntries;

	path = a.path;

	m_hasUnsureEntries = a.m_hasUnsureEntries;
	m_failed = a.m_failed;

	m_entryCount = a.m_entryCount;
	if (m_entryCount)
	{
		m_pEntries = new CDirentry[m_entryCount];
		for (unsigned int i = 0; i < m_entryCount; i++)
			m_pEntries[i] = a.m_pEntries[i];
	}
	else
		m_pEntries = 0;

	return *this;

}

