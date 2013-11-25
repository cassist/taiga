/*
** Taiga, a lightweight client for MyAnimeList
** Copyright (C) 2010-2012, Eren Okka
** 
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TAIGA_H
#define TAIGA_H

#include "base/std.h"
#include "update.h"
#include "version.h"

#include "win/win_main.h"

#define APP_NAME    L"Taiga"
#define APP_TITLE   L"Taiga 1.1a"
#define APP_VERSION L"1.1 alpha"
#define APP_BUILD   L"2013-11-19"

#ifndef PORTABLE
#define PORTABLE
#endif

enum PlayStatus {
  PLAYSTATUS_STOPPED,
  PLAYSTATUS_PLAYING,
  PLAYSTATUS_UPDATED
};

enum TipType {
  TIPTYPE_DEFAULT,
  TIPTYPE_NOWPLAYING,
  TIPTYPE_SEARCH,
  TIPTYPE_TORRENT,
  TIPTYPE_UPDATEFAILED
};

// =============================================================================

class Taiga : public win::App {
public:
  Taiga();
  ~Taiga();

  BOOL InitInstance();
  void Uninitialize();
  
public:
  wstring GetDataPath();
  void LoadData();

public:
  int current_tip_type, play_status;
  bool logged_in;
  int ticker_media, ticker_memory, ticker_new_episodes, ticker_queue;

  class Updater : public UpdateHelper {
  public:
    Updater() {}
    virtual ~Updater() {}

    void OnCheck();
    void OnCRCCheck(const wstring& path, wstring& crc);
    void OnDone();
    void OnProgress(int file_index);
    bool OnRestartApp();
    void OnRunActions();
  } Updater;
};

extern class Taiga Taiga;

#endif // TAIGA_H