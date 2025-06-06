import 'package:flutter/material.dart';

class Settings extends StatefulWidget {
  const Settings({super.key});

  @override
  State<Settings> createState() => _SettingsState();
}

class _SettingsState extends State<Settings> {
  bool _isDarkMode = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Settings'),
        backgroundColor: Colors.deepPurple.shade200,
      ),
      body: Center(
        child: SwitchListTile(
          title: const Text('Dark Mode'),
          value: _isDarkMode,
          onChanged: (bool value) {
            setState(() {
              _isDarkMode = value;
            });
            // Here you could also apply the theme change globally
          },
        ),
      ),
    );
  }
}
